# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

include_directories("${METAL_INCLUDE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_definitions(-DEXPECTED_METAL_MAJOR=${METAL_MAJOR})
add_definitions(-DEXPECTED_METAL_MINOR=${METAL_MINOR})
add_definitions(-DEXPECTED_METAL_PATCH=${METAL_PATCH})

add_custom_target(tests)
metal_build_test_tree(tests "${CMAKE_CURRENT_SOURCE_DIR}/src/")
