# Tadah!MD

Internal molecular-dynamics specialisation layer for the
[Tadah!](https://tadah.readthedocs.io/) MLIP toolchain. Provides:

- `M_KRR_MD` — KRR regressor optimised for the access pattern of the
  MD evaluation kernel.
- `M_BLR_MD` — BLR regressor counterpart.
- `M_MD_Base` — common base class for MD-side regressors.

These specialisations strip away analysis-only code paths from the
generic `M_KRR` / `M_BLR` regressors in [Tadah!MODELS], so the LAMMPS
plugin and any other on-line evaluator can run the inner loop without
the overhead of training-time bookkeeping.

[Tadah!MODELS]: https://git.ecdf.ed.ac.uk/tadah/models

## When you use this directly

Tadah!MD is consumed by [Tadah.LAMMPS] (the `pair_style tadah`
implementation) via `FetchContent`. End users do not interact with it
directly — they install Tadah.LAMMPS, which pulls Tadah!MD in
transitively.

[Tadah.LAMMPS]: https://git.ecdf.ed.ac.uk/tadah/tadah.lammps

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
- [Tadah!MODELS](https://git.ecdf.ed.ac.uk/tadah/models) — fetched
  automatically (which itself fetches Tadah!CORE).
- OpenMP (optional; enabled with `-DTADAH_ENABLE_OPENMP=ON`).

## Layout

| Path | Purpose |
|---|---|
| `include/tadah/md/m_md_base.h` | Common MD regressor base. |
| `include/tadah/md/m_krr_md.h`  | KRR specialisation. |
| `include/tadah/md/m_blr_md.h`  | BLR specialisation. |
| `src/m_md_base.cpp`, `src/m_md_all.cpp` | Implementations. |
| `tests/` | Unit tests. |

## License

GPL-3.0; see [LICENSE](LICENSE).

## Reporting issues

Bugs and feature requests:
[Tadah!MD issues](https://git.ecdf.ed.ac.uk/tadah/md/-/issues).
User-facing questions belong on
[Tadah!MLIP](https://git.ecdf.ed.ac.uk/tadah/tadah.mlip) (training /
prediction CLI) or
[Tadah!LAMMPS](https://git.ecdf.ed.ac.uk/tadah/tadah.lammps) (LAMMPS
runtime).
