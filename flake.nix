{
  description = "C/C++ development environment";

  inputs.nixpkgs.url = "nixpkgs/nixos-24.05";

  outputs = { self, nixpkgs, }:
    let
      supportedSystems = [
        "x86_64-linux"
        # "aarch64-linux"
        # "x86_64-darwin"
        # "aarch64-darwin"
      ];
      dirs = [ ./lab ./zylab ./assignment ];
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
      lib = import ./lib pkgs;
      labs = pkgs.lib.attrsets.mapAttrsToList (k: v: k) (lib.getDir ./lab);
    in {
      packages.${system} = pkgs.lib.attrsets.mergeAttrsList (map (lab: {
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
