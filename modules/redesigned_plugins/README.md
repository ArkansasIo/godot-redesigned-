# Redesigned Feature Plugin System

This module adds a native feature-extension layer to the redesigned Godot fork.

## Architecture

- `FeaturePlugin` — base `RefCounted` plugin contract.
- `FeaturePluginManager` — registry, lifecycle, priority ordering, enable/disable, and event dispatch.
- `FeaturePluginManager` is exposed as the engine singleton `FeaturePluginManager`.
- Plugins can be implemented in GDScript or native C++.

## Lifecycle

A plugin can implement:

- `initialize()`
- `shutdown()`
- `process(delta)`
- `on_feature_event(event, payload)`

Lifecycle methods are invoked through Godot's dynamic object call system so a
GDScript implementation can override the base methods.

## Registration example

```gdscript
var plugin := preload("res://plugins/basic_feature.gd").new()
FeaturePluginManager.register_plugin(plugin)
FeaturePluginManager.initialize_plugins()

func _process(delta: float) -> void:
    FeaturePluginManager.process_plugins(delta)

func start_game() -> void:
    FeaturePluginManager.dispatch_event(&"game_started", {"mode": "campaign"})
```

## Priorities

Higher `priority` values are initialized and processed first. This allows core
feature plugins to run before dependent plugins.

## Safety and ownership

The manager owns strong `Ref<FeaturePlugin>` references while a plugin is
registered. Unregistering a plugin invokes `shutdown()` before releasing it.
Plugin IDs must be unique.

## Intended uses

This layer is suitable for optional systems such as:

- rendering features
- editor tools
- networking features
- AI systems
- procedural generation
- gameplay frameworks
- analytics/debugging
- import/export extensions
- custom scripting services

The module deliberately does not impose a package format or remote code
execution mechanism. A future package manager can be layered on top of this
stable runtime registration API.
