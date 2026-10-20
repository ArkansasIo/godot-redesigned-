# Godot Redesigned

This repository is a fork of the [Godot Engine](https://github.com/godotengine/godot) source tree. It preserves the upstream build system and source layout while tracking project-specific redesign work.

## Project status

- **Upstream:** [godotengine/godot](https://github.com/godotengine/godot)
- **Default branch:** `master`
- **Engine version metadata:** see [version.py](version.py)
- **License:** MIT; see [LICENSE.txt](LICENSE.txt) and [COPYRIGHT.txt](COPYRIGHT.txt)
- **Project module:** `modules/redesign/`

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

## Redesign module

The first engine-side redesign layer is a small `redesign` module containing the `RedesignConfig` resource. It provides a configuration boundary for future editor/UI work without replacing Godot's theme or rendering systems.

See:

- [Module README](modules/redesign/README.md)
- [Module API](project_docs/REDESIGN_MODULE.md)
- [Design tokens](modules/redesign/design_tokens.json)
- [UML architecture](project_docs/REDESIGN_MODULE.uml)
- [Standalone example](redesign_examples/)

## Repository areas

| Path | Purpose |
| --- | --- |
| `.github/workflows/` | Build, static-check, and project-site workflows |
| `core/`, `servers/`, `scene/`, `editor/` | Engine implementation |
| `platform/` | Platform-specific code and integrations |
| `modules/` | Engine modules, including project-specific redesign code |
| `redesign_examples/` | Standalone example project |
| `project_docs/` | Fork-specific architecture and engineering documentation |
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

The project site lives under `docs/` and is deployed by `.github/workflows/project-pages.yml`. Engine builds and website deployment are intentionally separate workflows.

## Upstream resources

- [Godot Engine](https://godotengine.org/)
- [Official documentation](https://docs.godotengine.org/)
- [Compiling from source](https://docs.godotengine.org/en/latest/engine_details/development/compiling/)
- [Contributing guide](CONTRIBUTING.md)
- [MIT license](LICENSE.txt)

---

This fork is independently maintained by its repository owner. It is not an official Godot Engine release unless explicitly stated by the maintainers.
