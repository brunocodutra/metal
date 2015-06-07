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

option(BOOST_METAL_INCREASE_VERBOSITY "increase compiler verbosity" ON)
option(BOOST_METAL_ENABLE_WARNINGS "enable warnings" ON)
option(BOOST_METAL_ENABLE_EXTRA_WARNINGS "enable extra warnings" OFF)
option(BOOST_METAL_ENFORCE_STRICT_BEHAVIOR "enforce strict behavior" OFF)

if(BOOST_METAL_ENABLE_EXTRA_WARNINGS)
    set(BOOST_METAL_ENABLE_WARNINGS ON)
endif()

if(NOT BOOST_METAL_CXX_DIALECTS)
    set(BOOST_METAL_CXX_DIALECTS
        c++11
    )
    if(CXX_COMPILER_IS_GNU OR CXX_COMPILER_IS_CLANG)
        list(APPEND BOOST_METAL_CXX_DIALECTS
            c++14
            c++17
        )
    endif()
endif()

if(BOOST_METAL_INCREASE_VERBOSITY)
    diagnostics_flags(CXX BOOST_METAL_EXTRA_COMPILE_FLAGS)
endif()

if(BOOST_METAL_ENABLE_WARNINGS)
    warnings_flags(CXX BOOST_METAL_EXTRA_COMPILE_FLAGS)
    if(CXX_COMPILER_IS_MSVC)
        list(APPEND BOOST_METAL_EXTRA_COMPILE_FLAGS
            /wd4479
        )
    endif()

endif()

if(BOOST_METAL_ENABLE_EXTRA_WARNINGS)
    extra_warnings_flags(CXX BOOST_METAL_EXTRA_COMPILE_FLAGS)
    if(CXX_COMPILER_IS_GNU OR CXX_COMPILER_IS_CLANG)
        list(APPEND BOOST_METAL_EXTRA_COMPILE_FLAGS
            -Wno-c++98-compat
            -Wno-c++98-compat-pedantic
        )
    endif()
endif()

if(BOOST_METAL_ENFORCE_STRICT_BEHAVIOR)
    strict_behavior_flags(CXX BOOST_METAL_EXTRA_COMPILE_FLAGS)
endif()

if(CXX_COMPILER_IS_CLANG)
    check_flag(CXX "-stdlib=libc++ -include cstddef" result)
    if(result)
        list(APPEND BOOST_METAL_EXTRA_COMPILE_FLAGS
            -stdlib=libc++
        )
    endif()
endif()

add_compile_flags_globally("${BOOST_METAL_EXTRA_COMPILE_FLAGS}")

set(BOOST_METAL_TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE BOOST_METAL_TEST_HEADERS "${BOOST_METAL_TEST_INCLUDE_DIR}/*.hpp")
file(GLOB_RECURSE BOOST_METAL_TEST_SOURCES "src/*.cpp")

include_directories(${BOOST_METAL_INCLUDE_DIRS} ${BOOST_METAL_TEST_INCLUDE_DIR})
link_directories(${BOOST_METAL_LIBRARY_DIRS})

add_custom_target(metal.test)
add_dependencies(metal metal.test)
foreach(dialect ${BOOST_METAL_CXX_DIALECTS})
    unset(dialect_flags)
    language_dialect_flags(CXX ${dialect} dialect_flags)
    foreach(flag ${dialect_flags})
        check_flag(CXX "${flag}" flag)
        if(flag)
            add_custom_target(metal.test.${dialect})
            add_dependencies(metal.test metal.test.${dialect})
            foreach(SOURCE ${BOOST_METAL_TEST_SOURCES})
                string(REGEX REPLACE ".*[/\\](.*\)[.]cpp" "metal.test.${dialect}.\\1" test_target ${SOURCE})
                add_binary_target(
                    EXECUTABLE ${test_target}
                    LANGUAGE CXX
                    SOURCES ${SOURCE} ${BOOST_METAL_TEST_HEADERS}
                    LIBRARIES ${BOOST_METAL_LIBRARIES}
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
