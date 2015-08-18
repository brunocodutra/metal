// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/inherit.hpp>

#include "test.hpp"

using namespace metal;

using odds = inherit<test::num1, test::num3, test::num5, test::num7, test::num9>;

METAL_TEST_ASSERT((!std::is_base_of<test::num0, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::num1, odds>::value));
METAL_TEST_ASSERT((!std::is_base_of<test::num2, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::num3, odds>::value));
METAL_TEST_ASSERT((!std::is_base_of<test::num4, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::num5, odds>::value));
METAL_TEST_ASSERT((!std::is_base_of<test::num6, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::num7, odds>::value));
METAL_TEST_ASSERT((!std::is_base_of<test::num8, odds>::value));
METAL_TEST_ASSERT((std::is_base_of<test::num9, odds>::value));
