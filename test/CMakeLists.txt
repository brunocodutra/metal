# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(DetectToolchain)
include(CompilerUtilities)
include(TargetUtilities)
include(Warnings)
include(Diagnostics)
include(Strict)
include(Dialects)

option(METAL_INCREASE_VERBOSITY "increase compiler verbosity" ON)
option(METAL_ENABLE_WARNINGS "enable warnings" ON)
option(METAL_ENABLE_EXTRA_WARNINGS "enable extra warnings" OFF)
option(METAL_ENFORCE_STRICT_BEHAVIOR "enforce strict behavior" OFF)

if(METAL_ENABLE_EXTRA_WARNINGS)
    set(METAL_ENABLE_WARNINGS ON)
endif()

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

set(METAL_TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE METAL_TEST_HEADERS "${METAL_TEST_INCLUDE_DIR}/*.hpp")
file(GLOB_RECURSE METAL_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

include_directories(${METAL_INCLUDE_DIRS} ${METAL_TEST_INCLUDE_DIR})
link_directories(${METAL_LIBRARY_DIRS})

add_custom_target(metal.test)
foreach(dialect ${METAL_CXX_DIALECTS})
    unset(dialect_flags)
    language_dialect_flags(CXX ${dialect} dialect_flags)
    foreach(flag ${dialect_flags})
        check_flag(CXX "${flag}" flag)
        if(flag)
            add_custom_target(metal.test.${dialect})
            add_dependencies(metal.test metal.test.${dialect})
            foreach(SOURCE ${METAL_TEST_SOURCES})
                string(REGEX REPLACE ".*[/\\](.*\)[.]cpp" "metal.test.${dialect}.\\1" test_target ${SOURCE})
                add_binary_target(
                    EXECUTABLE ${test_target}
                    LANGUAGE CXX
                    SOURCES ${SOURCE} ${METAL_TEST_HEADERS}
                    LIBRARIES ${METAL_LIBRARIES}
                    ADITIONAL_FLAGS "${flag}"
                    DEPENDENCIES
                )
                add_test(${test_target} ${CMAKE_CURRENT_BINARY_DIR}/${test_target})
                add_dependencies(metal.test.${dialect} ${test_target})
            endforeach()
            break()
        endif()
    endforeach()
endforeach()
add_dependencies(metal.test metal)
