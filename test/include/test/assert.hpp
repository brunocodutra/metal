// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_ASSERT_HPP
#define METAL_TEST_ASSERT_HPP

#include "test/preprocessor.hpp"

#include <type_traits>

#define ASSERT_(X, Y) \
    static_assert(std::is_same<ID X, ID Y>::value, #X " == " #Y) \
/**/

#define ASSERT(EXPR, RESULT) ASSERT_(EXPR, RESULT)

#endif

