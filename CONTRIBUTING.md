# Contributing to MD

The full multi-repo contributor guide for the Tadah! project lives on
the umbrella repository:
<https://git.ecdf.ed.ac.uk/tadah/tadah.mlip/-/blob/develop/CONTRIBUTING.md>

This file covers what is specific to MD. Bug reports and feature
requests on this module use the GitLab issue tracker on this project;
cross-cutting changes (work that touches more than one Tadah! module)
should be discussed on the umbrella project first.

## Build & test in isolation

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build -j
ctest --test-dir build/tests --output-on-failure
```

In-source builds are blocked deliberately; always pick a separate
build directory.

### Dependencies

- C++17 compiler.
- [MODELS](https://git.ecdf.ed.ac.uk/tadah/models) — fetched
  automatically (which itself fetches CORE).
- OpenMP (optional; enabled with `-DTADAH_ENABLE_OPENMP=ON`).

## Layout

| Path | Purpose |
|---|---|
| `include/tadah/md/m_md_base.h` | Common MD regressor base. |
| `include/tadah/md/m_krr_md.h`  | KRR specialisation. |
| `include/tadah/md/m_blr_md.h`  | BLR specialisation. |
| `src/m_md_base.cpp`, `src/m_md_all.cpp` | Implementations. |
| `tests/` | Unit tests. |
