# Copyright Bruno Dutra 2015-2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

configure_targets(tests)
foreach(target ${targets})
    add_test(${target} ${CMAKE_CURRENT_BINARY_DIR}/${target})
endforeach()
