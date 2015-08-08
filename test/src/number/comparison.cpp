// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/comparison.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((equal_to_t<test::n0, integer<0>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::n1, integer<0>>::value));
METAL_TEST_ASSERT((equal_to_t<test::n2, integer<2>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::n3, integer<2>>::value));
METAL_TEST_ASSERT((equal_to_t<test::n4, integer<4>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::n5, integer<4>>::value));
METAL_TEST_ASSERT((equal_to_t<test::n6, integer<6>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::n7, integer<6>>::value));
METAL_TEST_ASSERT((equal_to_t<test::n8, integer<8>>::value));
METAL_TEST_ASSERT((!equal_to_t<test::n9, integer<8>>::value));

METAL_TEST_ASSERT((!greater_t<test::n0, integer<4>>::value));
METAL_TEST_ASSERT((!greater_t<test::n1, integer<4>>::value));
METAL_TEST_ASSERT((!greater_t<test::n2, integer<4>>::value));
METAL_TEST_ASSERT((!greater_t<test::n3, integer<4>>::value));
METAL_TEST_ASSERT((!greater_t<test::n4, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::n5, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::n6, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::n7, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::n8, integer<4>>::value));
METAL_TEST_ASSERT((greater_t<test::n9, integer<4>>::value));

METAL_TEST_ASSERT((less_t<test::n0, integer<5>>::value));
METAL_TEST_ASSERT((less_t<test::n1, integer<5>>::value));
METAL_TEST_ASSERT((less_t<test::n2, integer<5>>::value));
METAL_TEST_ASSERT((less_t<test::n3, integer<5>>::value));
METAL_TEST_ASSERT((less_t<test::n4, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::n5, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::n6, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::n7, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::n8, integer<5>>::value));
METAL_TEST_ASSERT((!less_t<test::n9, integer<5>>::value));
