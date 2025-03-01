{
  description = "Hackathon toolchain";

  outputs =
    { nixpkgs, ... }:
    {
      devShells.x86_64-linux =
        let
          pkgs = nixpkgs.legacyPackages.x86_64-linux;
        in
        {
          default = pkgs.mkShell {
            nativeBuildInputs = with pkgs; [
              cmake
              extra-cmake-modules
              pkg-config
              rocmPackages.llvm.clang
              rocmPackages.llvm.libunwind
            ];
          };
        };
    };
}
