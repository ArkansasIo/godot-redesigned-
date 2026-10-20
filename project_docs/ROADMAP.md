# Redesign Roadmap

This is a planning document. Items are proposals until implemented, reviewed, and tested.

## Phase 1 — Baseline and reproducibility

- [ ] Record the exact upstream base commit and local divergence.
- [ ] Confirm clean checkout and available SCons toolchain.
- [ ] Capture baseline build and static-check results.
- [ ] Define redesign goals, audience, and success metrics.

## Phase 2 — UX research and design system

- [ ] Audit editor workflows and identify measurable friction.
- [ ] Define color, spacing, typography, motion, and icon tokens.
- [ ] Specify keyboard focus, accessibility, localization, and scaling behaviors.
- [ ] Create mockups and obtain feedback before implementing broad UI changes.

## Phase 3 — Incremental implementation

- [ ] Split changes into small subsystem-scoped patches.
- [ ] Add regression tests for changed behavior.
- [ ] Benchmark editor startup, scene load, and relevant redraw paths.
- [ ] Validate high-DPI, multi-window, and alternate-platform behavior where relevant.

## Phase 4 — Release readiness

- [ ] Run platform-specific builds and tests.
- [ ] Produce reproducible build instructions and release notes.
- [ ] Check licensing and third-party notices.
- [ ] Publish signed or checksummed artifacts only when a release pipeline has produced them.
