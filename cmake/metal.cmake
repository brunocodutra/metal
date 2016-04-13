# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

include(CheckCXXCompilerFlag)

function(metal_try_add_flag _flag)
    set(result "${_flag}")
    string(TOUPPER "${result}" result)
    string(REGEX REPLACE "[+]" "X" result "${result}")
    string(REGEX REPLACE "[-/;=]" "_" result "${result}")
    string(REGEX REPLACE "[^ A-Z_0-9]" "" result "${result}")
    string(REGEX REPLACE "^[ ]*([A-Z_0-9]+) ?.*$" "\\1" result "${result}")
    set(result "HAS${result}")

    check_cxx_compiler_flag(${_flag} ${result})
    if(${result})
        add_compile_options(${_flag})
    endif()

    if(ARGN)
        set(${ARGN} ${result} PARENT_SCOPE)
    endif()
endfunction()

macro(get_parent_target _target)
    string(REGEX REPLACE "(.*)[.][^.]+" "\\1" parent_target ${_target})
endmacro()

function(metal_add_test_tree _root _prefix)
    if (NOT IS_DIRECTORY ${_prefix})
        message(FATAL_ERROR "${_prefix} is not a valid directory.")
    endif()

    file(GLOB_RECURSE headers ${_prefix}/include/*.hpp)
    list(SORT headers)

    file(GLOB_RECURSE sources ${_prefix}/src/*.cpp)
    list(SORT sources)

    set(targets)
    foreach(source ${sources})
        string(REPLACE "${_prefix}/src/" "" target ${source})
        string(REGEX REPLACE "[/\\]+" "." target ${target})
        string(REGEX REPLACE "(.*)[.]cpp" "${_root}.\\1" target ${target})
        add_executable(${target} EXCLUDE_FROM_ALL ${source} ${headers})
        target_include_directories(${target} PUBLIC ${_prefix}/include/)
        list(APPEND targets ${target})

        get_parent_target(${target})
        while(NOT TARGET ${parent_target})
            add_custom_target(${parent_target})
            add_dependencies(${parent_target} ${target})
            set(target ${parent_target})
            get_parent_target(${target})
        endwhile()
        add_dependencies(${parent_target} ${target})
    endforeach()

    list(REVERSE targets)
    foreach(target ${targets})
        add_test(
            NAME ${target}
            COMMAND ${CMAKE_COMMAND} --build . --target ${target}
            WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
        )
    endforeach()

    if(ARGN)
        list(REVERSE targets)
        set(${ARGN} ${targets} PARENT_SCOPE)
    endif()
endfunction()
