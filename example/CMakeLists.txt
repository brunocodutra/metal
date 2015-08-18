# Copyright Bruno Dutra 2015
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

add_test_matrix(
    metal.example
    "${METAL_CXX_DIALECTS}"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
add_dependencies(metal.example metal)
