# Redesign Module API

## Purpose

The engine-side redesign module provides a small configuration boundary for future editor and UI work. It deliberately avoids embedding visual policy throughout the engine.

## Class: `RedesignConfig`

| Property | Type | Default | Purpose |
| --- | --- | --- | --- |
| `high_contrast` | `bool` | `false` | Enables a higher-contrast presentation profile. |
| `compact_mode` | `bool` | `false` | Requests reduced UI density. |
| `reduced_motion` | `bool` | `false` | Suppresses non-essential motion in consumers. |
| `accent_color` | `Color` | `#65D7D0` | Primary project accent. |
| `density` | `String` | `comfortable` | UI density profile identifier. |

## Serialization

`to_dictionary()` returns a plain `Dictionary` suitable for project settings, configuration migration, or editor tooling. `from_dictionary()` accepts partial dictionaries, so future versions can add properties without requiring every old configuration to contain them.

## Non-goals

- It does not replace `Theme` or `ThemeDB`.
- It does not modify renderer behavior.
- It does not persist user preferences by itself.
- It does not claim compatibility with every platform until tested.

## Extension rule

New properties should have a consumer, a documented default, and a migration/test story before they are added to this resource.
