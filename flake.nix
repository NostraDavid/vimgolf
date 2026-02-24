{
  description = "VimGolf on NixOS (reproducible devshell + runnable app)";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        lib = pkgs.lib;

        # Try to use vimgolf from nixpkgs if it exists; otherwise fall back to a wrapper
        # that installs the gem into a project-local GEM_HOME the first time you run it.
        vimgolfFromNixpkgs =
          lib.attrByPath [ "rubyPackages" "vimgolf" ] null pkgs;

        ruby = pkgs.ruby;

        vimgolfWrapper = pkgs.writeShellApplication {
          name = "vimgolf";
          runtimeInputs = [
            ruby
            pkgs.vim
            pkgs.git
            pkgs.cacert
            pkgs.openssl
          ];
          text = ''
            set -euo pipefail

            # Project-local gem home for determinism and no pollution of ~/.local
            GEM_HOME="$(pwd)/.gem"
            export GEM_HOME
            export GEM_PATH="$GEM_HOME"
            export PATH="$GEM_HOME/bin:$PATH"

            # Keep bundler noise down; avoid system bundler configs interfering.
            export BUNDLE_IGNORE_CONFIG=1

            VIMGOLF_BIN="$GEM_HOME/bin/vimgolf"

            if [ ! -x "$VIMGOLF_BIN" ]; then
              echo "Installing vimgolf gem into $GEM_HOME ..."
              mkdir -p "$GEM_HOME"
              # Needs network access to rubygems.org the first time.
              gem install vimgolf --no-document
            fi

            exec "$VIMGOLF_BIN" "$@"
          '';
        };

        vimgolfPkg =
          if vimgolfFromNixpkgs != null then vimgolfFromNixpkgs else vimgolfWrapper;

      in {
        packages.default = vimgolfPkg;

        apps.default = {
          type = "app";
          program = "${vimgolfPkg}/bin/vimgolf";
        };

        devShells.default = pkgs.mkShell {
          packages = [
            ruby
            pkgs.vim
            pkgs.git

            # For native extensions (racc/debug/etc.) if Ruby decides to build any.
            pkgs.gcc
            pkgs.gnumake
            pkgs.pkg-config
            pkgs.openssl
            pkgs.zlib
            pkgs.libyaml
            pkgs.ncurses
            pkgs.readline

            vimgolfPkg
          ];

          shellHook = ''
            export THOR_SILENCE_DEPRECATION=1
            echo "Ready. Try: vimgolf setup  (or)  vimgolf put <challenge_id>"
          '';
        };
      });
}
