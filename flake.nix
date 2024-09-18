{
  description = "Data Structures (C++)";

  inputs.nixpkgs.url = "nixpkgs/nixos-24.05";
  inputs.nix-lib-monadam.url = "git+file:/home/adam/code/nix-lib-monadam";
  inputs.nix-lib-monadam.inputs.nixpkgs.follows = "nixpkgs";

  outputs = { self, nixpkgs, nix-lib-monadam }:
    let
      system = "x86_64-linux";
      lib = nix-lib-monadam.lib;
      pkgs = import nixpkgs { inherit system; };
      labs = lib.getDirs ./lab;
      zylabs = lib.getDirs ./zylab;
      assignments = lib.getDirs ./assignment;
      labPackages = pkgs.lib.attrsets.mergeAttrsList (map (lab: {
        "lab-${lab}" = pkgs.stdenv.mkDerivation rec {
          name = "lab-${lab}";
          src = ./lab/${lab};
          installPhase = ''
            mkdir -p $out/bin
            cp Lab $out/bin/${name}
          '';
          meta.mainProgram = name;
        };
      }) labs);
      assignmentPackages = pkgs.lib.attrsets.mergeAttrsList (map (assignment: {
        "assignment-${assignment}" = pkgs.stdenv.mkDerivation rec {
          name = "assignment-${assignment}";
          src = ./assignment/${assignment};
          installPhase = ''
            mkdir -p $out/bin
            cp Assignment $out/bin/${name}
          '';
          meta.mainProgram = name;
        };
      }) assignments);
      zylabPackages = pkgs.lib.attrsets.mergeAttrsList (map (zylab: {
        "zylab-${zylab}" = pkgs.stdenv.mkDerivation rec {
          name = "zylab-${zylab}";
          src = ./zylab/${zylab};
          installPhase = ''
            mkdir -p $out/bin
            cp Zylab $out/bin/${name}
          '';
          meta.mainProgram = name;
        };
      }) zylabs);
    in {
      packages.${system} = labPackages // zylabPackages // assignmentPackages;

      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs;
          [
            (writeShellScriptBin "nix-build-package" ''
              REALPATH=realpath $1
              nix-build -E 'with import <nixpkgs> {}; callPackage "$REALPATH" {}'
            '')
            clang-tools
            cmake
            codespell
            conan
            cppcheck
            doxygen
            gtest
            lcov
            vcpkg
            vcpkg-tool
          ] ++ (if system == "aarch64-darwin" then [ ] else [ gdb ]);
      };
    };
}
