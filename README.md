[![pipeline](https://git.ecdf.ed.ac.uk/tadah/md/badges/v1-dev/pipeline.svg)](https://git.ecdf.ed.ac.uk/tadah/md/-/commits/v1-dev)
[![coverage](https://git.ecdf.ed.ac.uk/tadah/md/badges/v1-dev/coverage.svg)](https://git.ecdf.ed.ac.uk/tadah/md/-/commits/v1-dev)
[![license](https://img.shields.io/badge/license-GPL--3.0-blue.svg)](LICENSE)
[![version](https://img.shields.io/badge/version-1.6.0-blue.svg)](https://git.ecdf.ed.ac.uk/tadah/md/-/tags)

# MD

Molecular-dynamics specialisation layer of the
[Tadah!](https://tadah.readthedocs.io/v1-dev/) MLIP toolchain. Provides:

- `M_KRR_MD` — KRR regressor optimised for the access pattern of the
  MD evaluation kernel.
- `M_BLR_MD` — BLR regressor counterpart.
- `M_MD_Base` — common base class for MD-side regressors.

These specialisations strip away analysis-only code paths from the
generic `M_KRR` / `M_BLR` regressors in
[MODELS](https://git.ecdf.ed.ac.uk/tadah/models) so the LAMMPS
plugin and any other on-line evaluator can run the inner loop without
the overhead of training-time bookkeeping.

## You don't need to use this directly

MD is an internal module of the Tadah! MLIP toolchain. It is
fetched automatically (via CMake `FetchContent`) by
[Tadah!LAMMPS](https://git.ecdf.ed.ac.uk/tadah/tadah.lammps) (the
`pair_style tadah` implementation) and by
[HPO](https://git.ecdf.ed.ac.uk/tadah/hpo). End users install
the umbrella project
[Tadah!MLIP](https://git.ecdf.ed.ac.uk/tadah/tadah.mlip) or Tadah!LAMMPS
— see the
[installation guide](https://tadah.readthedocs.io/v1-dev/installation.html).

## Contributing

Build instructions, dependencies, and layout live in
[CONTRIBUTING.md](CONTRIBUTING.md). The full multi-repo contributor
guide is on the umbrella project.

## License

GPL-3.0; see [LICENSE](LICENSE).

## Reporting issues

Bugs and feature requests:
[MD issues](https://git.ecdf.ed.ac.uk/tadah/md/-/issues).
For end-user questions please use the umbrella project
[Tadah!MLIP](https://git.ecdf.ed.ac.uk/tadah/tadah.mlip) or
[Tadah!LAMMPS](https://git.ecdf.ed.ac.uk/tadah/tadah.lammps).
