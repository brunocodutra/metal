# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

include(CheckCXXCompilerFlag)

macro(add_flag _flag)
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

macro(get_headers)
    file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
    list(SORT headers)
endmacro()

macro(get_sources)
    file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
    list(SORT sources)
endmacro()

macro(get_target _root _source)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/src/" "" target ${_source})
    string(REGEX REPLACE "[/\\]" "." target ${target})
    string(REGEX REPLACE "(.*)[.]cpp" "${_root}.\\1" target ${target})
endmacro()

macro(get_parent _target)
    string(REGEX REPLACE "(.*)[.][^.]+" "\\1" parent ${_target})
endmacro()

function(attach_parents _target)
    get_parent(${_target})
    while(NOT TARGET ${parent})
        add_custom_target(${parent})
        add_dependencies(${parent} ${_target})
        set(_target ${parent})
        get_parent(${_target})
    endwhile()
    add_dependencies(${parent} ${_target})
endfunction()

macro(configure_targets _root)
    get_headers()
    get_sources()

    set(targets)
    foreach(source ${sources})
        get_target(${_root} ${source})
        add_executable(${target} EXCLUDE_FROM_ALL ${source} ${headers})

        attach_parents(${target})
        list(APPEND targets ${target})
    endforeach()
endmacro()
