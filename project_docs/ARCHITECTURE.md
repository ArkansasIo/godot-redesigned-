# Architecture Overview

## Engine layers

Godot is a modular C++ engine with platform abstraction, scene/object systems, rendering, resource management, editor tooling, and scripting language integration.

| Area | Primary source directory | Responsibility |
| --- | --- | --- |
| Core runtime | `core/` | Fundamental types, objects, strings, containers, and runtime utilities |
| Main application | `main/` | Startup, engine lifecycle, and application entry points |
| Scene system | `scene/` | Nodes, scenes, resources, and gameplay-facing APIs |
| Editor | `editor/` | Project editing, inspectors, importers, and authoring UI |
| Rendering and servers | `servers/` | Rendering and other server-side engine abstractions |
| Platforms | `platform/` | OS and platform-specific integrations |
| Modules | `modules/` | Optional or specialized engine capabilities |
| Third-party | `thirdparty/` | Bundled external dependencies; preserve license notices |
| Tests | `tests/` | Automated test suites and test assets |

## Redesign principles

1. **Upstream-compatible:** minimize unnecessary divergence and document cherry-pick/rebase strategy.
2. **Modular:** isolate features by subsystem; prefer existing extension points.
3. **Data-driven:** where relevant, keep editor-facing configuration in resources instead of hard-coded constants.
4. **Testable:** changes to core behavior should include regression coverage.
5. **Cross-platform:** do not assume one platform's filesystem, windowing, input, or graphics behavior is universal.
6. **Accessible UI:** maintain keyboard navigation, readable contrast, scalable interface layouts, and localization readiness.

## Change design record

For each substantial redesign, document:

- user problem and intended outcome;
- affected subsystems and public APIs;
- platform/rendering implications;
- compatibility and migration plan;
- performance risks;
- test cases and rollback approach.
