# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

set(EXCLUDE)
if(NOT Boost_FOUND)
    list(APPEND EXCLUDE "external")
else()
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_custom_target(test.header)
header_test_tree(Metal test.header ${METAL_INCLUDE_DIR} EXCLUDE ${EXCLUDE})
