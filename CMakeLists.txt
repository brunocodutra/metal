# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.4)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")
endif()

project(Metal CXX)

option(METAL_STRICT                 "treat compiler warnings as errors"     OFF)
option(METAL_VERBOSE                "increase output verbosity"             OFF)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(Deploy)
include(TestTree)
include(CompileFlags)

set(METAL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")

file(STRINGS "${METAL_INCLUDE_DIR}/metal/config/version.hpp"
    METAL_CONFIG_VERSION_HPP REGEX "METAL_[A-Z]+ [0-9]+" LIMIT_COUNT 3
)

LIST(GET METAL_CONFIG_VERSION_HPP 0 METAL_MAJOR)
LIST(GET METAL_CONFIG_VERSION_HPP 1 METAL_MINOR)
LIST(GET METAL_CONFIG_VERSION_HPP 2 METAL_PATCH)

string(REGEX REPLACE ".*MAJOR ([0-9]+).*" "\\1" METAL_MAJOR "${METAL_MAJOR}")
string(REGEX REPLACE ".*MINOR ([0-9]+).*" "\\1" METAL_MINOR "${METAL_MINOR}")
string(REGEX REPLACE ".*PATCH ([0-9]+).*" "\\1" METAL_PATCH "${METAL_PATCH}")

set(METAL_VERSION "${METAL_MAJOR}.${METAL_MINOR}.${METAL_PATCH}")

message(STATUS "Configuring Metal ${METAL_VERSION}")

add_library(Metal INTERFACE)
set_target_properties(Metal PROPERTIES
    INTERFACE_LIB_VERSION ${METAL_VERSION}
    INTERFACE_INCLUDE_DIRECTORIES ${METAL_INCLUDE_DIR}
)

target_compile_flags(Metal INTERFACE -W)
target_compile_flags(Metal INTERFACE -Wextra)
target_compile_flags(Metal INTERFACE -pedantic)

if(NOT MSVC)
    target_compile_flags(Metal INTERFACE -Wall)
endif()

if(METAL_STRICT)
    target_compile_flags(Metal INTERFACE -pedantic-errors)
    target_compile_flags(Metal INTERFACE -Werror)
    target_compile_flags(Metal INTERFACE /Za)
    target_compile_flags(Metal INTERFACE /WX)
endif()

if(METAL_VERBOSE)
    target_compile_flags(Metal INTERFACE -v)
    target_compile_flags(Metal INTERFACE -ftemplate-backtrace-limit=0)
    target_compile_flags(Metal INTERFACE -fdiagnostics-show-template-tree)
    target_compile_flags(Metal INTERFACE -fno-elide-type)
endif()

target_compile_flags(Metal INTERFACE -stdlib=libc++ LIBS c++ c++abi)

target_compile_flags(Metal INTERFACE /std:c++latest)

target_compile_flags(Metal INTERFACE -std=c++17
    FALLBACK -std=c++1z -std=c++14 -std=c++1y -std=c++11 -std=c++0x
)

deploy(Metal)

enable_testing()

find_package(Boost)

add_subdirectory(doc)
add_subdirectory(example)
add_subdirectory(test)
