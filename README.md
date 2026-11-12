# OVERGLAD
> C++17 Wrapper Over GLAD Loader

Wrapper for OpenGL 4.6 compatibility profile (no extensions) based on glad 2.0.8 generator

## Branches

- `glad`: _versions `0.0.*` just CMake wrapper, still required C++17 by interface (change it?)_
- `main`: _versions `0.1+` C++ namespace and functionality wrapper_

## GLAD
> original `<glad/gl.h>` split into several headers to allow partial functionality inclusion

- `<glad/son8.hxx>`:
  - `<glad/son8/gl.h>`: original header that includes all split parts below
    - `<glad/son8/gl/header.h>`: type aliases with khronos header
    - `<glad/son8/gl/source.h>`: glad api pointers and call global variables (includes `header.h`)
    - `<glad/son8/gl/loader.h>`: just loader functions (includes `header.h`)
    - `<glad/son8/gl/define.h>`:
      - `<glad/son8/gl/define/macros.h>`: defines gl procedures macros (includes `source.h`)
      - `<glad/son8/gl/define/values.h>`: defines gl enum constant values (includes nothing)

## [CONTRIBUTING](./CONTRIBUTING.md)
> Project Contribution Rules

## [LICENSE](./LICENSE) [Apache-2.0](./LICENSE.Apache-2.0.md) [NOTICE](./NOTICE)
> Project Copying Rules with attribution notice

###### each folder MAY contain README with additional materials
