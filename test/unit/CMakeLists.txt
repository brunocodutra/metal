# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_definitions(-DEXPECTED_METAL_MAJOR=${METAL_MAJOR})
add_definitions(-DEXPECTED_METAL_MINOR=${METAL_MINOR})
add_definitions(-DEXPECTED_METAL_PATCH=${METAL_PATCH})

set(EXCLUDE)
if(NOT Boost_FOUND)
    list(APPEND EXCLUDE "mpl")
else()
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_custom_target(test.unit)
unit_test_tree(Metal test.unit "${CMAKE_CURRENT_SOURCE_DIR}/src" EXCLUDE ${EXCLUDE})
