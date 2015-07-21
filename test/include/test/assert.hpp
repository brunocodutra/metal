// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_ASSERT_HPP
#define METAL_TEST_ASSERT_HPP

#define METAL_TEST_ASSERT_FWD(EXPR) static_assert(EXPR, #EXPR)
#define METAL_TEST_ASSERT(EXPR) METAL_TEST_ASSERT_FWD(EXPR)

#endif
