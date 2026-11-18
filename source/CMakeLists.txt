set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

add_library( ${SON8_LIB} INTERFACE )

if ( SON8_OVERGLAD_DUMMY_FACE_BUILD )

    set( SON8_OVERGLAD_DUMMY_FACE overglad-dummy_face )
    add_library( ${SON8_OVERGLAD_DUMMY_FACE} STATIC )
    target_sources( ${SON8_OVERGLAD_DUMMY_FACE} PRIVATE ${SON8_OVERGLAD_DUMMY_FACE}.cxx )
    target_link_libraries( ${SON8_OVERGLAD_DUMMY_FACE} PRIVATE ${SON8_LIB} )
    target_compile_options( ${SON8_OVERGLAD_DUMMY_FACE} PRIVATE
        $<$<CXX_COMPILER_ID:GNU>:
            -Wall
            -Wextra
            -Wpedantic
            -Wshadow
            -Wconversion
            -Wsign-conversion
            -Wdouble-promotion
            -Wnull-dereference
            -Wcast-align
            -Wnon-virtual-dtor
            -Woverloaded-virtual
            -Wduplicated-cond
            -Wduplicated-branches
            -Wlogical-op
            -Wuseless-cast
            -Wformat=2

            -Werror=return-type

            -Wno-missing-field-initializers
        >
    )
endif( )

# Apache License 2.0
# NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
# SPDX-License-Identifier: Apache-2.0
# lib: `overglad` C++17 Wrapper Over GLAD Loader
# Ⓒ Copyright (c) 2025-2026 Oleg'Ease'Kharchuk ᦒ
