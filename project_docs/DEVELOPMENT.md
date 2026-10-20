# Development Workflow

## Requirements

Follow the official [compiling guide](https://docs.godotengine.org/en/latest/engine_details/development/compiling/) for platform prerequisites and current supported build options. Godot's required toolchain changes over time; do not treat an old local compiler setup as authoritative.

## Explore configuration

```sh
python -c "import SCons; print(SCons.__version__)"
scons --help
```

## Example editor build

For a Linux/BSD host, after the documented dependencies are installed:

```sh
scons platform=linuxbsd target=editor
```

This is an example, not a guarantee that the current machine has the correct toolchain or dependencies. Choose the platform and target supported by the host and consult `scons --help`.

## Recommended branch workflow

1. Create a descriptive topic branch.
2. Make one logical change at a time.
3. Run formatting/static checks appropriate for touched files.
4. Run focused subsystem tests, followed by broader checks when practical.
5. Record exact commands, tool versions, output, and known limitations in the pull request.
6. Compare against upstream before merging large updates.

## Commit hygiene

- Avoid committing generated `bin/` output and local editor state.
- Preserve upstream copyright and license headers.
- Avoid unrelated mass formatting.
- Do not replace upstream project documentation without explaining the fork-specific intent.
