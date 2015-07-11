# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

set(METAL_EXAMPLE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE METAL_EXAMPLE_HEADERS "${METAL_EXAMPLE_INCLUDE_DIR}/*.hpp")
file(GLOB_RECURSE METAL_EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

include_directories(${METAL_EXAMPLE_INCLUDE_DIR})

add_test_matrix(
    metal.example
    "${METAL_CXX_DIALECTS}"
    "${METAL_EXAMPLE_SOURCES}"
    "${METAL_EXAMPLE_HEADERS}"
)
add_dependencies(metal.example metal)
