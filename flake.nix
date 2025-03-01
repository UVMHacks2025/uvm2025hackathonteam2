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
          default = pkgs.mkShell rec {
            buildInputs = with pkgs; [

            ];
            nativeBuildInputs = with pkgs; [
              # Tooling
              cmake
              extra-cmake-modules
              libgcc
              pkg-config
              rocmPackages.llvm.clang
              rocmPackages.llvm.libunwind
            ];
            LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath buildInputs;
          };
        };
    };
}
