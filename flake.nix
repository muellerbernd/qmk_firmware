{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs = {
    self,
    nixpkgs,
    flake-utils,
    ...
  }:
    flake-utils.lib.eachDefaultSystem
    (system: let
      # pkgs = nixpkgs.outputs.legacyPackages.${system};
      pkgs = import nixpkgs {
        inherit system;

        # config.permittedInsecurePackages = [
        #   "olm-3.2.16"
        # ];
      };
      # avrlibc = pkgsCross.avr.libcCross;
      # avr_incflags = [
      #   "-isystem ${avrlibc}/avr/include"
      #   "-B${avrlibc}/avr/lib/avr5"
      #   "-L${avrlibc}/avr/lib/avr5"
      #   "-B${avrlibc}/avr/lib/avr35"
      #   "-L${avrlibc}/avr/lib/avr35"
      #   "-B${avrlibc}/avr/lib/avr51"
      #   "-L${avrlibc}/avr/lib/avr51"
      # ];
    in {
      devShells.default = with pkgs;
        mkShell {
          name = "qmk devShell";
          # buildInputs =
          #   [clang-tools_11 dfu-programmer dfu-util diffutils git pythonEnv niv]
          #   ++ lib.optional avr [
          #     pkgsCross.avr.buildPackages.binutils
          #     pkgsCross.avr.buildPackages.gcc8
          #     avrlibc
          #     avrdude
          #   ]
          #   ++ lib.optional arm [gcc-arm-embedded]
          #   ++ lib.optional teensy [teensy-loader-cli];
          buildInputs = [qmk];

          # AVR_CFLAGS = lib.optional avr avr_incflags;
          # AVR_ASFLAGS = lib.optional avr avr_incflags;
          shellHook = ''
            # Prevent the avr-gcc wrapper from picking up host GCC flags
            # like -iframework, which is problematic on Darwin
            # unset NIX_CFLAGS_COMPILE_FOR_TARGET
          '';
        };
    })
    // {
      # overlays.default = final: prev: {
      # };
    };
}
