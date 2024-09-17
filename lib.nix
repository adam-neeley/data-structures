{ lib }:
with builtins;
with lib; rec {
  getDir = dir:
    mapAttrs
    (file: type: if (type == "directory") then getDir "$dir/$file" else type)
    readDir dir;
  files = dir:
    collect isString
    (mapAttrsRecursive (path: type: concatStringsSep "/" path) (getDir dir));
  packageFiles = dir:
    map (file: ./. + "/${file}")
    (filter (file: file == "package.nix") (files dir));
}
