# Godot Redesigned

This repository is a fork of the [Godot Engine](https://github.com/godotengine/godot) source tree. It preserves the upstream build system and source layout while tracking project-specific redesign work.

## Project status

- **Upstream:** [godotengine/godot](https://github.com/godotengine/godot)
- **Default branch:** `master`
- **Engine version metadata:** see [version.py](version.py)
- **License:** MIT; see [LICENSE.txt](LICENSE.txt) and [COPYRIGHT.txt](COPYRIGHT.txt)

This README describes the fork and its contribution workflow. It does not imply that custom engine changes or release binaries have been validated.

## Build the engine

Godot is built from source using SCons. Always follow the [official compiling guide](https://docs.godotengine.org/en/latest/engine_details/development/compiling/).

Typical setup after installing the platform prerequisites and SCons:

```sh
# Inspect available build options first.
python -c "import SCons; print('SCons', SCons.__version__)"
scons --help

# Example editor build (choose options appropriate for your platform).
scons platform=linuxbsd target=editor
```

The example command is for Linux/BSD environments; platform names and prerequisites differ. Build output is normally written beneath `bin/`, which is ignored by Git.

## Repository areas

| Path | Purpose |
| --- | --- |
| `.github/workflows/` | Upstream platform build and static-check workflows |
| `core/`, `servers/`, `scene/`, `editor/` | Engine implementation |
| `platform/` | Platform-specific code and integrations |
| `modules/` | Engine modules |
| `tests/` | Automated tests and test data |
| `thirdparty/` | Third-party dependencies and their license notices |
| `doc/` | Engine documentation sources |

## Contribution workflow

1. Create a focused branch for each redesign or engine change.
2. Keep changes isolated from unrelated upstream updates.
3. Run the relevant static checks and tests for the modified subsystem.
4. Attach reproduction steps, platform details, build options, and logs to bug reports.
5. Review third-party license obligations before adding or replacing dependencies.

## GitHub Pages

The engine source repository is not itself a deployable website. If GitHub Pages is enabled for this repository, publish a separate project overview from a dedicated folder or branch rather than attempting to render the C++ source tree as a site. Keep engine builds and web-site deployment as separate workflows.

## Upstream resources

- [Godot Engine](https://godotengine.org/)
- [Official documentation](https://docs.godotengine.org/)
- [Compiling from source](https://docs.godotengine.org/en/latest/engine_details/development/compiling/)
- [Contributing guide](CONTRIBUTING.md)
- [MIT license](LICENSE.txt)

---

This fork is independently maintained by its repository owner. It is not an official Godot Engine release unless explicitly stated by the maintainers.
