// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/nothing.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((is_nothing_t<nothing>::value));

METAL_TEST_ASSERT((is_nothing_t<test::val0>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val1>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val2>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val3>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val4>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val5>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val6>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val7>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val8>::value));
METAL_TEST_ASSERT((is_nothing_t<test::val9>::value));

METAL_TEST_ASSERT((!is_nothing_t<test::num0>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num1>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num2>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num3>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num4>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num5>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num6>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num7>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num9>::value));
METAL_TEST_ASSERT((!is_nothing_t<test::num9>::value));
