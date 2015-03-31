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

extra_warnings_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)
diagnostics_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)
strict_behavior_flags(CXX BOOST_MPL2_EXTRA_COMPILE_FLAGS)
list(APPEND BOOST_MPL2_EXTRA_COMPILE_FLAGS
    -Wno-c++98-compat
    -Wno-c++98-compat-pedantic
    -Wno-disabled-macro-expansion
)

if(CXX_COMPILER_IS_CLANG)
    list(APPEND BOOST_MPL2_EXTRA_COMPILE_FLAGS
        -Wno-unused-local-typedef
    )
endif()

add_compile_flags_globally("${BOOST_MPL2_EXTRA_COMPILE_FLAGS}")

file(GLOB_RECURSE BOOST_MPL2_TEST_HEADERS "*.hpp")
file(GLOB_RECURSE BOOST_MPL2_TEST_SOURCES "*.cpp")

include_directories(${BOOST_MPL2_INCLUDE_DIRS})
link_directories(${BOOST_MPL2_LIBRARY_DIRS})

option(BOOST_MPL2_ENABLE_CXX11 "test c++11" ON)
if(BOOST_MPL2_ENABLE_CXX11)
    set(BOOST_MPL2_ENABLED_DIALECTS ${BOOST_MPL2_ENABLED_DIALECTS} c++11)
endif()

option(BOOST_MPL2_ENABLE_CXX14 "test c++14" ON)
if(BOOST_MPL2_ENABLE_CXX14)
    set(BOOST_MPL2_ENABLED_DIALECTS ${BOOST_MPL2_ENABLED_DIALECTS} c++14)
endif()

if(CXX_COMPILER_IS_MSVC)
    option(BOOST_MPL2_ENABLE_MSVC_DIALECTS "test msvc dialects" OFF)
    if(BOOST_MPL2_ENABLE_MSVC_DIALECTS)
        set(BOOST_MPL2_ENABLED_DIALECTS ${BOOST_MPL2_ENABLED_DIALECTS} msvc++)
    endif()
else()
    option(BOOST_MPL2_ENABLE_GNU_DIALECTS "test gnu dialects" OFF)
    if(BOOST_MPL2_ENABLE_GNU_DIALECTS)
        string(REGEX REPLACE "[cC][+][+]" "gnu++" BOOST_MPL2_ENABLED_GNU_DIALECTS "${BOOST_MPL2_ENABLED_DIALECTS}")
        set(BOOST_MPL2_ENABLED_DIALECTS ${BOOST_MPL2_ENABLED_DIALECTS} ${BOOST_MPL2_ENABLED_GNU_DIALECTS})
    endif()
endif()

foreach(dialect ${BOOST_MPL2_ENABLED_DIALECTS})
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
