#!/usr/bin/env python3
"""Validate the project-specific redesign module layout without building Godot."""

from pathlib import Path
import json
import sys

ROOT = Path(__file__).resolve().parents[2]
REQUIRED = [
    "modules/redesign/SCsub",
    "modules/redesign/register_types.h",
    "modules/redesign/register_types.cpp",
    "modules/redesign/redesign_config.h",
    "modules/redesign/redesign_config.cpp",
    "modules/redesign/design_tokens.json",
    "modules/redesign/README.md",
    "project_docs/REDESIGN_MODULE.md",
    "project_docs/REDESIGN_MODULE.uml",
    "redesign_examples/project.godot",
    "redesign_examples/main.tscn",
    "redesign_examples/main.gd",
]


def main() -> int:
    missing = [path for path in REQUIRED if not (ROOT / path).is_file()]
    if missing:
        print("Missing redesign module files:")
        for path in missing:
            print(f"  - {path}")
        return 1

    tokens = ROOT / "modules/redesign/design_tokens.json"
    try:
        data = json.loads(tokens.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as exc:
        print(f"Invalid design token JSON: {exc}")
        return 1

    for section in ("colors", "spacing", "radius", "motion", "accessibility"):
        if section not in data:
            print(f"Missing design token section: {section}")
            return 1

    registration = (ROOT / "modules/redesign/register_types.cpp").read_text(encoding="utf-8")
    if "initialize_redesign_module" not in registration or "GDREGISTER_CLASS(RedesignConfig)" not in registration:
        print("Redesign module registration is incomplete.")
        return 1

    print(f"Redesign module validation passed: {len(REQUIRED)} required files present.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
