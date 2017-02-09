# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_custom_target(example)
unit_test_tree(Metal example "${CMAKE_CURRENT_SOURCE_DIR}/src/")

add_custom_target(examples DEPENDS example)
