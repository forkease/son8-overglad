## CHANGES
> [keep a changelog](https://keepachangelog.com/en/1.1.0/) with [semantic versioning](https://semver.org/spec/v2.0.0.html)

## Branch: glad

### v0.0.8 - 2026-11-12

#### Fixed

- `GLAPI` and `GLAPIENTRY` macros not exposed when including only split header (useful for example for debug callback)
- incorrect inclusion of extern "C" for C compilers

### v0.0.7 - 2026-11-05
> Breaking change

#### Changes (Breaking)
> reason (`<glad/gl.h>`) seems to generic position that could possibly cause issues with system path

- moved headers inside `glad/include/glad/son8` to `gl` subfolder
- moved `glad/include/glad/gl.h` to `son8` subfolder

### v0.0.6 - 2026-04-20
> add license related notices and other documentation related adjustments

### v0.0.5 - 2025-12-18
> add `glad/son8.hxx` header

### v0.0.4 - 2025-12-15
> add specific MSVC option to correctly work with __cplusplus macro

### v0.0.3 - 2025-12-04
> split define header into macros and values headers

### v0.0.2 - 2025-12-03

#### Added
> Makefile and it's usage, MSVC specific compile options

#### Changed
> code formatting and READMES and other comments wording, cmake small restructure

#### Fixed
> editorconfig comment bug

### v0.0.1 - 2025-02-04
> initial tag
