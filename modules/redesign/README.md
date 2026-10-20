# Godot Redesigned Engine Module

The `redesign` module is the first engine-side integration layer for project-specific UX configuration.

## Current API

`RedesignConfig` is a `Resource` that stores presentation preferences without hard-coding them into individual editor controls:

- `high_contrast`
- `compact_mode`
- `reduced_motion`
- `accent_color`
- `density`

The resource is intentionally small. New behavior should be added only when there is a concrete engine/editor consumer and regression coverage.

## Build integration

The module is discovered through the existing Godot module build system. Its `SCsub` adds the C++ sources, while `register_types.cpp` exposes the public runtime class.

Build the engine using the normal Godot SCons workflow. If a build fails, record the exact platform, compiler, SCons command, and first diagnostic rather than treating later cascading errors as independent failures.

## Design boundary

This module does not replace Godot's editor theme system. It provides a stable configuration object that future editor tooling can consume. Visual styling belongs in the editor/UI layer; persistent preferences belong in configuration; core engine behavior should remain independent of presentation choices.
