// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/comparison.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((equal_to_t<test::num0, integer<0>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::num1, integer<0>>::value));
METAL_TEST_ASSERT((equal_to_t<test::num2, integer<2>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::num3, integer<2>>::value));
METAL_TEST_ASSERT((equal_to_t<test::num4, integer<4>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::num5, integer<4>>::value));
METAL_TEST_ASSERT((equal_to_t<test::num6, integer<6>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::num7, integer<6>>::value));
METAL_TEST_ASSERT((equal_to_t<test::num8, integer<8>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::num9, integer<8>>::value));

METAL_TEST_ASSERT((!greater_t<test::num0, integer<4>>::value));
METAL_TEST_ASSERT((!greater_t<test::num1, integer<4>>::value));
METAL_TEST_ASSERT((!greater_t<test::num2, integer<4>>::value));
METAL_TEST_ASSERT((!greater_t<test::num3, integer<4>>::value));
METAL_TEST_ASSERT((!greater_t<test::num4, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::num5, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::num6, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::num7, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::num8, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::num9, integer<4>>::value));

METAL_TEST_ASSERT((less_t<test::num0, integer<5>>::value));
METAL_TEST_ASSERT((less_t<test::num1, integer<5>>::value));
METAL_TEST_ASSERT((less_t<test::num2, integer<5>>::value));
METAL_TEST_ASSERT((less_t<test::num3, integer<5>>::value));
METAL_TEST_ASSERT((less_t<test::num4, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::num5, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::num6, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::num7, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::num8, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::num9, integer<5>>::value));
