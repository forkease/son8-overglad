cmake_minimum_required( VERSION 3.14...3.27 )
project( overglad VERSION 0.0.7 LANGUAGES CXX )
set( SON8_LIB son8__${PROJECT_NAME} )
# Private configuration under source directory
add_subdirectory( source )
add_library( son8::${PROJECT_NAME} ALIAS ${SON8_LIB} )

add_subdirectory( glad )
target_link_libraries( ${SON8_LIB} INTERFACE glad::son8 )
target_compile_features( ${SON8_LIB} INTERFACE cxx_std_17 )
target_compile_options( ${SON8_LIB} INTERFACE $<$<CXX_COMPILER_ID:MSVC>:/utf-8 /permissive- /Zc:__cplusplus> )

# Apache License 2.0
# NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0>
# SPDX-License-Identifier: Apache-2.0
# lib: `overglad` C++17 Wrapper Over GLAD Loader
# Ⓒ Copyright (c) 2025-2026 Oleg'Ease'Kharchuk ᦒ
