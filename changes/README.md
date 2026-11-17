## CHANGES
> [keep a changelog](https://keepachangelog.com/en/1.1.0/) with [semantic versioning](https://semver.org/spec/v2.0.0.html)

## Branch: main

### `v0.9.1` - 2026-11-12

#### Added
- shader sources passing via `source()` and `sources` procedures

#### Fixed
- merge glad `v0.0.8` changes

### `v0.9.0` - 2026-11-05
> TODO: changes description

### `v0.8.3` - 2026-11-03

#### Added

- Info class and info functions that design to retrieve informational logs about shader and program compilation status
- Tiny, Small, Middle, Average, Default, Common, Large, Huge aliases for Info class buffer capacity from `64 Bytes` to `8 KiB`

#### Changed

- Objects, Shader, Program, and Attib one argument constructors explicit

### `v0.8.2` - 2026-07-24

#### Added

- `overglad::enums` `Capi` or index capability for `GL_SCISSOR_TEST` named simply `Capi::Scissor`

### `v0.8.1` - 2026-04-20
> merge glad 0.0.6 version, that almost all related to licensing transition

### `v0.8.0` - 2026-04-19
> mostly license related updates with some sneak in changes

#### Changed
> change license from `BSL-1.0` to `Apache-2.0`

- `overglad` header:
  - enums: rename `MatrixMode` to `Matrix`
- `v1_1` header:
  - rename procedure `matrix_mode` to `mode`
  - move `is_texture` procedure from deprecated section to core

### `v0.6.1` - 2025-12-18
> merged glad 0.0.5 version, that just added glad `son8` header

### `v0.6.0` - 2025-12-15
> mostly refactoring and building related changes, but added special generic object type creation/deletion

#### Added

- `Makefile`
- merge glad split define header into macros and values
- `v1_1` header:
  - generic `gen`, `del`, `bind` family of functions for OpenGL object maintenance through most versions
- `overglad` header:
  - types: `Object` and `Objects`
  - alias: many `Object` related
  - `Attrib` class validate method for compile time validation of correct generic parameters
  - TODO and many OpenGL 4.6 related functionality

#### Changed

- replace double quotes file inclusion in favor of angle brackets
- use `GLvoid` instead of void
- replace using C++17 none-standard conforming `static_assert` false with some compile-time generic ones
- `overglad` header:
  - fix `Clearbit` bit or operator not being `constexpr`
  - complicate helper class `Capi` implementation

##### Removed
- `Buf` and `Bufs` helper classes in favor of more generic `Object` and `Objects`

### `v0.5.0` - 2025-07-17
> OpenGL 4.3 related functionality

#### Added

- `v4_3` header: TODO and most of deprecated functionality
- `overglad` header: base header should contain OpenGL 4.6 (latest) related functionality
  - enums: Barrier

### `v0.4.0` - 2025-07-10
> OpenGL 3.3 related functionality

#### Added

- `v3_3` header additions
- `overglad` header:
  - enums: `Capi` and internal `Capi_` helper class, `Clamp`, `ClampColor`, `Packed`, `Provoke`
  - types: `Packed` struct helper
  - alias: `Enablei`, `Disablei` for `Capi_` helper, `array1ui`, packed related

### `v0.3.1` - 2025-07-10
> fix using `gl*` instead of `glad_gl*` function calls that intended to be used outside of deprecated realm, as `gl*` ones are not available without deprecated macro

### `v0.3.0` - 2025-07-06
> mostly additions to support OpenGL 2.1 functionality

#### Added

- `v2_1` header: large chunks of OpenGL 2.1 functionality and TODO
- `overglad` header:
  - include standard `type_traits` header into `overglad` header
  - enums: `Shader`, "dummy" `Program` enum
  - types: `Attrib`, `Shader` and `Program` class wrappers
  - alias: `attrib` related

### `v0.2.0` - 2025-07-04
> most changes related to adding OpenGL 1.5 functionality

#### Added

- `v1_5` header: TODO, most of deprecated, core and compatibility functionality of OpenGL 1.5
- `overglad` header:
  - include standard `cassert` header into `overglad` header
  - enums: Access, Buffer, Equation, Multi, Usage
  - types: `Buf` and `Bufs` templated class wrappers for Buffer enums
  - alias: for array and element buffers of `Buf` and `Bufs` types

#### Changed
> added new fields to enums Capabilities

### `v0.1.0` - 2025-05-16
> init `overglad` include headers structure with basic enums and types namespaces

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

### `v0.0.6` - 2026-04-20
> add license related notices and other documentation related adjustments

### `v0.0.5` - 2025-12-18
> add `glad/son8.hxx` header

### `v0.0.4` - 2025-12-15
> add specific `MSVC` option to correctly work with `__cplusplus` macro

### `v0.0.3` - 2025-12-04
> split define header into macros and values headers

### `v0.0.2` - 2025-12-03

#### Added
> `Makefile` and it usage, MSVC specific compile options

#### Changed
> code formatting and `READMES` and other comments wording, `CMake` small restructure

#### Fixed
> `editorconfig` comment bug

### `v0.0.1` - 2025-02-04
> initial tag
