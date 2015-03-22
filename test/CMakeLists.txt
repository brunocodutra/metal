# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(CompilerUtilities)
include(TargetUtilities)
include(Warnings)
include(Diagnostics)
include(Strict)
include(Dialects)

extra_warnings_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)
diagnostics_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)
strict_behavior_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)

add_compile_flags_globally("${BOOST_MPL2_EXTRA_COMPILE_FLAGS}")

file(GLOB_RECURSE BOOST_MPL2_TEST_HEADERS "*.hpp")
file(GLOB_RECURSE BOOST_MPL2_TEST_SOURCES "*.cpp")

include_directories(${BOOST_MPL2_INCLUDE_DIRS})
link_directories(${BOOST_MPL2_LIBRARY_DIRS})

set(BOOST_MPL2_TEST_DIALECTS c++98 c++03 c++11 c++14)

option(BOOST_MPL2_TEST_GNU_DIALECTS "test gnu dialects" ON)
if(BOOST_MPL2_TEST_GNU_DIALECTS)
    set(BOOST_MPL2_TEST_DIALECTS ${BOOST_MPL2_TEST_DIALECTS} gnu++98 gnu++03 gnu++11 gnu++14)
endif()

option(BOOST_MPL2_TEST_MSVC_DIALECTS "test msvc dialects" OFF)
if(BOOST_MPL2_TEST_MSVC_DIALECTS)
    set(BOOST_MPL2_TEST_DIALECTS ${BOOST_MPL2_TEST_DIALECTS} msvc++)
endif()

foreach(dialect ${BOOST_MPL2_TEST_DIALECTS})
    set(dialect_flag)
    language_dialect_flags(CXX ${dialect} dialect_flag)
    foreach(SOURCE ${BOOST_MPL2_TEST_SOURCES})
        string(REGEX REPLACE ".*[/\\](.*\)[.]cpp" "\\1_test_${dialect}" target ${SOURCE})
        add_binary_target(
            EXECUTABLE ${target}
            LANGUAGE CXX
            SOURCES ${SOURCE} ${BOOST_MPL2_TEST_HEADERS}
            LIBRARIES ${BOOST_MPL2_LIBRARIES}
            ADITIONAL_FLAGS ${dialect_flag}
            DEPENDENCIES mpl2
        )
        add_test(${target} ${CMAKE_CURRENT_BINARY_DIR}/${target})
        set(BOOST_MPL2_TEST_TARGETS ${BOOST_MPL2_TEST_TARGETS} ${target})
    endforeach()
endforeach()

add_custom_target(tests DEPENDS ${BOOST_MPL2_TEST_TARGETS})
add_custom_command(
    TARGET tests
    COMMENT "unity tests"
    POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND}
    ARGS --output-on-failure
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
