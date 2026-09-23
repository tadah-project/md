# Changelog

All notable changes to **Tadah.MD** (lightweight molecular-dynamics drivers used by HPO/examples) are documented here.
Format follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

## [Unreleased]

## [1.5.1] — 2026-09-23

### Changed
- Framework version `1.5.1`, read from CORE's `blueprint/blueprint_tadah.toml` after the Tadah dependencies are fetched, so the module reports the right version in every layout (sibling checkout or FetchContent). A missing blueprint is now a configure error instead of a silent `0.0.0`.

## [1.4.0] — 2026-07-14

Nothing yet.

## [1.3.0-beta.1] — 2026-05-20

A small module with mostly cross-cutting build / infrastructure updates.

### Changed
- C++ standard upgraded from C++14 to **C++17**.

### Fixed
- `M_MD_Base` factory now uses `Registry::instance()` instead of a static map — fixes static-initialisation order across translation units.

### Added
- `TADAH_ENABLE_ASAN` CMake option.

### Internal
- Substantive README rewrite (Session B).
- Community / governance pointer files added.
- CI/CD: lint + release stages, VERSION wired from blueprint TOML.
- Test build routed through `cmake-tools/cmake/TadahTesting.cmake` helpers (`tadah_declare_testing` / `tadah_add_tests`).

## [1.2.0] and earlier (condensed)

The `v1.0.0` → `v1.1.1` releases were the "internal playground" era. MD remained a thin orchestration layer in this period; releases primarily comprised build-system fixes and typo corrections. No published changelog covers this era; treat anything before `1.3.0-beta.1` as undocumented in the modern sense.
