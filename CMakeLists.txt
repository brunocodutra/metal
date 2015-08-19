# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 2.8.3)

project(Metal CXX)

option(METAL_INCREASE_VERBOSITY         "increase compiler verbosity"        ON)
option(METAL_ENABLE_WARNINGS            "enable warnings"                    ON)
option(METAL_ENABLE_EXTRA_WARNINGS      "enable extra warnings"             OFF)
option(METAL_ENFORCE_STRICT_BEHAVIOR    "enforce strict behavior"           OFF)
option(METAL_CONFIGURE_TESTS            "configure tests"                    ON)

if(METAL_ENABLE_EXTRA_WARNINGS)
    set(METAL_ENABLE_WARNINGS ON)
endif()

find_package(Doxygen)
find_package(Git)
enable_testing()

function(add_test_matrix _target _dialects _prefix)
    file(GLOB_RECURSE headers "${_prefix}/include/*.hpp")
    file(GLOB_RECURSE sources "${_prefix}/src/*.cpp")
    list(SORT sources)
    include_directories("${_prefix}/include")
    add_custom_target(${_target})
    foreach(dialect ${_dialects})
        unset(dialect_flags)
        language_dialect_flags(CXX ${dialect} dialect_flags)
        foreach(flag ${dialect_flags})
            check_flag(CXX "${flag}" flag)
            if(flag)
                add_custom_target(${_target}.${dialect})
                add_dependencies(${_target} ${_target}.${dialect})
                foreach(source ${sources})
                    string(REPLACE "${_prefix}/src/" "" test_target ${source})
                    string(REGEX REPLACE "[/\\]" "." test_target ${test_target})
                    string(
                        REGEX REPLACE
                        "(.*)[.]cpp"
                        "${_target}.${dialect}.\\1"
                        test_target
                        ${test_target}
                    )

                    add_binary_target(
                        EXECUTABLE ${test_target}
                        LANGUAGE CXX
                        SOURCES ${source} ${headers}
                        LIBRARIES
                        ADITIONAL_FLAGS "${flag}"
                        DEPENDENCIES
                    )
                    add_test(
                        ${test_target}
                        ${CMAKE_CURRENT_BINARY_DIR}/${test_target}
                    )

                    string(
                        REGEX REPLACE
                        "(.*)[.][^.]+"
                        "\\1"
                        test_target_parent
                        ${test_target}
                    )

                    while(NOT TARGET ${test_target_parent})
                        add_custom_target(${test_target_parent})
                        add_dependencies(${test_target_parent} ${test_target})
                        set(test_target ${test_target_parent})
                        string(
                            REGEX REPLACE
                            "(.*)[.][^.]+"
                            "\\1"
                            test_target_parent
                            ${test_target}
                        )
                    endwhile()

                    add_dependencies(${test_target_parent} ${test_target})
                endforeach()
                break()
            endif()
        endforeach()
    endforeach()
endfunction()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(DetectToolchain)
include(CompilerUtilities)
include(TargetUtilities)
include(Warnings)
include(Diagnostics)
include(Strict)
include(Dialects)

if(NOT METAL_CXX_DIALECTS)
    set(METAL_CXX_DIALECTS
        c++11
    )
    if(CXX_COMPILER_IS_GNU OR CXX_COMPILER_IS_CLANG)
        list(APPEND METAL_CXX_DIALECTS
            c++14
            c++17
        )
    endif()
endif()

if(METAL_INCREASE_VERBOSITY)
    diagnostics_flags(CXX METAL_EXTRA_COMPILE_FLAGS)
endif()

if(METAL_ENABLE_WARNINGS)
    warnings_flags(CXX METAL_EXTRA_COMPILE_FLAGS)
    if(CXX_COMPILER_IS_MSVC)
        list(APPEND METAL_EXTRA_COMPILE_FLAGS
            /wd4479
        )
    endif()

endif()

if(METAL_ENABLE_EXTRA_WARNINGS)
    extra_warnings_flags(CXX METAL_EXTRA_COMPILE_FLAGS)
    if(CXX_COMPILER_IS_GNU OR CXX_COMPILER_IS_CLANG)
        list(APPEND METAL_EXTRA_COMPILE_FLAGS
            -Wno-c++98-compat
            -Wno-c++98-compat-pedantic
            -Wno-documentation
            -Wno-documentation-unknown-command
        )
    endif()
endif()

if(METAL_ENFORCE_STRICT_BEHAVIOR)
    strict_behavior_flags(CXX METAL_EXTRA_COMPILE_FLAGS)
endif()

if(CXX_COMPILER_IS_CLANG)
    check_flag(CXX "-stdlib=libc++ -include cstddef" result)
    if(result)
        list(APPEND METAL_EXTRA_COMPILE_FLAGS
            -stdlib=libc++
        )
    endif()
endif()

add_compile_flags_globally("${METAL_EXTRA_COMPILE_FLAGS}")

set(METAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(METAL_INCLUDE_DIRS ${METAL_INCLUDE_DIR})

file(GLOB_RECURSE METAL_HEADERS ${METAL_INCLUDE_DIR}/*.hpp)

add_custom_target(metal SOURCES ${METAL_HEADERS})
install(FILES ${METAL_HEADERS} DESTINATION include)

include_directories(${METAL_INCLUDE_DIRS})

add_subdirectory(doc)
add_subdirectory(example)

if(METAL_CONFIGURE_TESTS)
    add_subdirectory(test)
endif()
