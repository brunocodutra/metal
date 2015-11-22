# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.8)

project(Metal CXX)

option(METAL_VERBOSE                "increase output verbosity"             OFF)
option(METAL_ENABLE_BASIC_WARNINGS  "enable basic compiler warnings"         ON)
option(METAL_ENABLE_EXTRA_WARNINGS  "enable extra compiler warnings"        OFF)
option(METAL_STRICT                 "treat compiler warnings as errors"     OFF)

if(METAL_ENABLE_EXTRA_WARNINGS)
    set(METAL_ENABLE_BASIC_WARNINGS ON)
endif()

enable_testing()
include(CheckCXXCompilerFlag)

function(metal_add_test_tree _tree)
    file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
    file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
    list(SORT sources)

    foreach(source ${sources})
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/src/" "" target ${source})
        string(REGEX REPLACE "[/\\]" "." target ${target})
        string(REGEX REPLACE "(.*)[.]cpp" "${_tree}.\\1" target ${target})

        add_executable(${target} ${source} ${headers})
        add_test(${target} ${CMAKE_CURRENT_BINARY_DIR}/${target})

        string(REGEX REPLACE "(.*)[.][^.]+" "\\1" parent ${target})
        while(NOT TARGET ${parent})
            add_custom_target(${parent})
            add_dependencies(${parent} ${target})
            set(target ${parent})
            string(REGEX REPLACE "(.*)[.][^.]+" "\\1" parent ${target})
        endwhile()
        add_dependencies(${parent} ${target})
    endforeach()
endfunction()

macro(metal_add_flag _flag)
    set(result "${_flag}")
    string(TOUPPER "${result}" result)
    string(REGEX REPLACE "[+]" "X" result "${result}")
    string(REGEX REPLACE "[-/;=]" "_" result "${result}")
    string(REGEX REPLACE "[^ A-Z_0-9]" "" result "${result}")
    string(REGEX REPLACE "^[ ]*([A-Z_0-9]+) ?.*$" "\\1" result "${result}")
    set(result "HAS${result}")

    check_cxx_compiler_flag("${_flag} ${ARGN}" ${result})
    if(${result})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${_flag}")
    endif()
endmacro()

if(METAL_VERBOSE)
    metal_add_flag(-v)
    metal_add_flag(-ftemplate-backtrace-limit=0)
    metal_add_flag(-fdiagnostics-show-template-tree)
    metal_add_flag(-fno-elide-type)
endif()

if(METAL_ENABLE_BASIC_WARNINGS)
    metal_add_flag(-W)
    metal_add_flag(-Wall)
    metal_add_flag(/W3)
endif()

if(METAL_ENABLE_EXTRA_WARNINGS)
    metal_add_flag(-Wextra)
    metal_add_flag(-Weverything)
    metal_add_flag(-Wno-c++98-compat)
    metal_add_flag(-Wno-c++98-compat-pedantic)
    metal_add_flag(-Wno-documentation-unknown-command)
    metal_add_flag(/W4)
endif()

if(METAL_STRICT)
    metal_add_flag(-pedantic-errors)
    metal_add_flag(-Werror)
    metal_add_flag(/WX)
endif()

metal_add_flag(-stdlib=libc++ "-include cstddef")
metal_add_flag(-ftemplate-depth=512)

foreach(dialect
    -std=c++17 -std=c++1z
    -std=c++14 -std=c++1y
    -std=c++11 -std=c++0x
    /Za
)
    metal_add_flag(${dialect})
    if(${result})
        break()
    endif()
endforeach()

set(METAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)
file(GLOB_RECURSE METAL_HEADERS ${METAL_INCLUDE_DIR}/*.hpp)

include_directories(${METAL_INCLUDE_DIR})

install(DIRECTORY ${METAL_INCLUDE_DIR} DESTINATION include)

add_subdirectory(doc)
add_subdirectory(example)
add_subdirectory(test)
