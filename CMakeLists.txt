# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.1)

project(Metal CXX)

set(METAL_MAJOR_VERSION 0)
set(METAL_MINOR_VERSION 1)
set(METAL_PATCH_VERSION 0)
set(
    METAL_VERSION
    ${METAL_MAJOR_VERSION}.${METAL_MINOR_VERSION}.${METAL_PATCH_VERSION}
)

if(WIN32 AND NOT CYGWIN)
  set(METAL_CMAKE_INSTALL_DIR_DEF CMake)
else()
  set(METAL_CMAKE_INSTALL_DIR_DEF lib/cmake/Metal)
endif()

set(METAL_CMAKE_INSTALL_DIR
    ${METAL_CMAKE_INSTALL_DIR_DEF} CACHE PATH
    "installation directory for Metal CMake files"
)

set(METAL_INCLUDE_INSTALL_DIR
    include CACHE PATH
    "installation directory for Metal header files"
)

option(METAL_VERBOSE                "increase output verbosity"             OFF)
option(METAL_ENABLE_BASIC_WARNINGS  "enable basic compiler warnings"        OFF)
option(METAL_ENABLE_EXTRA_WARNINGS  "enable extra compiler warnings"        OFF)
option(METAL_STRICT                 "treat compiler warnings as errors"     OFF)

if(METAL_ENABLE_EXTRA_WARNINGS)
    set(METAL_ENABLE_BASIC_WARNINGS ON)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(metal)

if(METAL_VERBOSE)
    metal_try_add_flag(-v)
    metal_try_add_flag(-ftemplate-backtrace-limit=0)
    metal_try_add_flag(-fdiagnostics-show-template-tree)
    metal_try_add_flag(-fno-elide-type)
endif()

if(METAL_ENABLE_BASIC_WARNINGS)
    metal_try_add_flag(-W)
    metal_try_add_flag(-Wall)
    metal_try_add_flag(/W3)
endif()

if(METAL_ENABLE_EXTRA_WARNINGS)
    metal_try_add_flag(-Wextra)
    metal_try_add_flag(/W4)
endif()

if(METAL_STRICT)
    metal_try_add_flag(-pedantic-errors)
    metal_try_add_flag(-Werror)
    metal_try_add_flag(/WX)
endif()

foreach(dialect
    -std=c++17 -std=c++1z
    -std=c++14 -std=c++1y
    -std=c++11 -std=c++0x
    /Za
)
    metal_try_add_flag(${dialect} result)
    if(${result})
        break()
    endif()
endforeach()

set(METAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)
file(GLOB_RECURSE METAL_HEADERS "${METAL_INCLUDE_DIR}/*.hpp")

include_directories("${METAL_INCLUDE_DIR}")

enable_testing()

add_subdirectory(doc)
add_subdirectory(example)
add_subdirectory(test)

foreach(_ INCLUDE CMAKE)
  if(NOT IS_ABSOLUTE "${METAL_${_}_INSTALL_DIR}")
    set(
        METAL_${_}_INSTALL_DIR
        "${CMAKE_INSTALL_PREFIX}/${METAL_${_}_INSTALL_DIR}"
    )
  endif()
endforeach()

file(
    RELATIVE_PATH METAL_INCLUDE_DIRS_CONF
    "${METAL_CMAKE_INSTALL_DIR}" "${METAL_INCLUDE_INSTALL_DIR}"
)

set(METAL_INCLUDE_DIRS_CONF "\${METAL_CMAKE_DIR}/${METAL_INCLUDE_DIRS_CONF}")
configure_file(
    cmake/MetalConfig.cmake.in
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfig.cmake"
    @ONLY
)

configure_file(
    cmake/MetalConfigVersion.cmake.in
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfigVersion.cmake"
    @ONLY
)

install(
    DIRECTORY "${METAL_INCLUDE_DIR}"
    DESTINATION "${METAL_INCLUDE_INSTALL_DIR}"
)

install(
    FILES
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfig.cmake"
    "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MetalConfigVersion.cmake"
    DESTINATION "${METAL_CMAKE_INSTALL_DIR}"
)
