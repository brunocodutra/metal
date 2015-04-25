# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(DetectToolchain)
include(CompilerUtilities)
include(TargetUtilities)
include(Warnings)
include(Diagnostics)
include(Strict)
include(Dialects)

diagnostics_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)

option(BOOST_MPL2_ENABLE_EXTRA_WARNINGS "enable extra warnings" ON)
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
    set(BOOST_MPL2_CXX_DIALECTS c++11)
endif()

foreach(dialect ${BOOST_MPL2_CXX_DIALECTS})
    set(dialect_flag)
    language_dialect_flags(CXX ${dialect} dialect_flag)
    if(NOT "${dialect_flag}" MATCHES "-NOTFOUND$")
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
    endif()
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
