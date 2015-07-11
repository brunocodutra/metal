# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

set(METAL_TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE METAL_TEST_HEADERS "${METAL_TEST_INCLUDE_DIR}/*.hpp")
file(GLOB_RECURSE METAL_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

include_directories(${METAL_TEST_INCLUDE_DIR})

add_test_matrix(
    metal.test
    "${METAL_CXX_DIALECTS}"
    "${METAL_TEST_SOURCES}"
    "${METAL_TEST_HEADERS}"
)
add_dependencies(metal.test metal)
