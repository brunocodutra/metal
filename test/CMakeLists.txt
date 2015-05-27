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

option(BOOST_MPL2_ENHANCE_DIAGNOSTICS "increase compiler verbosity" ON)
if(BOOST_MPL2_ENHANCE_DIAGNOSTICS)
    diagnostics_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)
endif()

option(BOOST_MPL2_ENABLE_EXTRA_WARNINGS "enable extra warnings" OFF)
if(BOOST_MPL2_ENABLE_EXTRA_WARNINGS)
    extra_warnings_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)
    list(APPEND BOOST_MPL2_EXTRA_COMPILE_FLAGS
        -Wno-c++98-compat
        -Wno-c++98-compat-pedantic
    )
endif()

option(BOOST_MPL2_ENABLE_STRICT_BEHAVIOR "enable strict behavior" OFF)
if(BOOST_MPL2_ENABLE_STRICT_BEHAVIOR)
    strict_behavior_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)
endif()

add_compile_flags_globally("${BOOST_MPL2_EXTRA_COMPILE_FLAGS}")

file(GLOB_RECURSE BOOST_MPL2_TEST_HEADERS "*.hpp")
file(GLOB_RECURSE BOOST_MPL2_TEST_SOURCES "*.cpp")

include_directories(${BOOST_MPL2_INCLUDE_DIRS})
link_directories(${BOOST_MPL2_LIBRARY_DIRS})

if(NOT BOOST_MPL2_CXX_DIALECTS)
    set(BOOST_MPL2_CXX_DIALECTS
        c++11
        c++14
        c++17
    )
endif()

add_custom_target(mpl2.test)
add_dependencies(mpl2 mpl2.test)
foreach(dialect ${BOOST_MPL2_CXX_DIALECTS})
    unset(dialect_flag)
    language_dialect_flags(CXX ${dialect} dialect_flag)
    if(NOT "${dialect_flag}" MATCHES "-NOTFOUND$")
        add_custom_target(mpl2.test.${dialect})
        add_dependencies(mpl2.test mpl2.test.${dialect})
        foreach(SOURCE ${BOOST_MPL2_TEST_SOURCES})
            string(REGEX REPLACE ".*[/\\](.*\)[.]cpp" "mpl2.test.${dialect}.\\1" test_target ${SOURCE})
            add_binary_target(
                EXECUTABLE ${test_target}
                LANGUAGE CXX
                SOURCES ${SOURCE} ${BOOST_MPL2_TEST_HEADERS}
                LIBRARIES ${BOOST_MPL2_LIBRARIES}
                ADITIONAL_FLAGS ${dialect_flag}
                DEPENDENCIES
            )
            add_test(${test_target} ${CMAKE_CURRENT_BINARY_DIR}/${test_target})
            add_dependencies(mpl2.test.${dialect} ${test_target})
        endforeach()
    endif()
endforeach()
