# Quality and Testing Strategy

## Testing layers

### Static validation
Run the repository's existing static-check workflow and hooks for modified files. The workflow currently provides formatting, file-format, and documentation checks; consult `.github/workflows/static_checks.yml`.

### Unit and subsystem tests
Use the existing test infrastructure and add regression cases near the subsystem being modified. Keep tests deterministic, isolated from network services, and explicit about platform requirements.

### Integration tests
Exercise the complete user-visible workflow changed by a patch: editor launch, project opening, resource import, scene editing, or runtime execution as applicable.

### Platform matrix
At minimum, assess the target operating system and rendering driver. For user-facing UI changes, include high-DPI and different window-size checks. Include headless/server configurations when the modified subsystem is used there.

## Bug report template

- **Godot version / base commit:**
- **Operating system and architecture:**
- **Graphics backend / driver:**
- **Build options and compiler:**
- **Steps to reproduce:**
- **Expected behavior:**
- **Actual behavior:**
- **Logs / crash dump:**
- **Regression range:**
- **Workaround:**

## Completion checklist

- [ ] The issue is reproducible or the behavior is specified.
- [ ] The fix is narrowly scoped.
- [ ] Regression coverage is included where practical.
- [ ] Relevant static checks pass.
- [ ] Relevant build/test commands and results are recorded.
- [ ] Documentation and migration notes are updated.
