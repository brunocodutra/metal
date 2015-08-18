// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/logical.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_just<or_<>>::value));
METAL_TEST_ASSERT((!is_just<or_<test::val0>>::value));
METAL_TEST_ASSERT((!is_just<or_<test::num0, test::val1>>::value));
METAL_TEST_ASSERT((!is_just<or_<test::val0, test::num1, test::val2>>::value));
METAL_TEST_ASSERT((!is_just<or_<test::num0, test::val1, test::num2, test::val3>>::value));

METAL_TEST_ASSERT((or_t<test::num1>::value));
METAL_TEST_ASSERT((or_t<test::num0, test::num2>::value));
METAL_TEST_ASSERT((or_t<test::num0, test::num0, test::num3>::value));
METAL_TEST_ASSERT((or_t<test::num0, test::num0, test::num0, test::num4>::value));
METAL_TEST_ASSERT((or_t<test::num0, test::num0, test::num0, test::num0, test::num5>::value));
METAL_TEST_ASSERT((or_t<test::num0, test::num0, test::num0, test::num0, test::num0, test::num6>::value));
METAL_TEST_ASSERT((or_t<test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num7>::value));
METAL_TEST_ASSERT((or_t<test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num8>::value));
METAL_TEST_ASSERT((or_t<test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num8, test::num9>::value));

METAL_TEST_ASSERT((!or_t<test::num0>::value));
METAL_TEST_ASSERT((!or_t<test::num0, test::num0>::value));
METAL_TEST_ASSERT((!or_t<test::num0, test::num0, test::num0>::value));
METAL_TEST_ASSERT((!or_t<test::num0, test::num0, test::num0, test::num0>::value));
METAL_TEST_ASSERT((!or_t<test::num0, test::num0, test::num0, test::num0, test::num0>::value));
METAL_TEST_ASSERT((!or_t<test::num0, test::num0, test::num0, test::num0, test::num0, test::num0>::value));
METAL_TEST_ASSERT((!or_t<test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num0>::value));
METAL_TEST_ASSERT((!or_t<test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num0>::value));
METAL_TEST_ASSERT((!or_t<test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num0, test::num0>::value));

METAL_TEST_ASSERT((!is_just<and_<>>::value));
METAL_TEST_ASSERT((!is_just<and_<test::val0>>::value));
METAL_TEST_ASSERT((!is_just<and_<test::num0, test::val1>>::value));
METAL_TEST_ASSERT((!is_just<and_<test::val0, test::num1, test::val2>>::value));
METAL_TEST_ASSERT((!is_just<and_<test::num0, test::val1, test::num2, test::val3>>::value));

METAL_TEST_ASSERT((and_t<test::num1>::value));
METAL_TEST_ASSERT((and_t<test::num1, test::num2>::value));
METAL_TEST_ASSERT((and_t<test::num1, test::num2, test::num3>::value));
METAL_TEST_ASSERT((and_t<test::num1, test::num2, test::num3, test::num4>::value));
METAL_TEST_ASSERT((and_t<test::num1, test::num2, test::num3, test::num4, test::num5>::value));
METAL_TEST_ASSERT((and_t<test::num1, test::num2, test::num3, test::num4, test::num5, test::num6>::value));
METAL_TEST_ASSERT((and_t<test::num1, test::num2, test::num3, test::num4, test::num5, test::num6, test::num7>::value));
METAL_TEST_ASSERT((and_t<test::num1, test::num2, test::num3, test::num4, test::num5, test::num6, test::num7, test::num8>::value));
METAL_TEST_ASSERT((and_t<test::num1, test::num2, test::num3, test::num4, test::num5, test::num6, test::num7, test::num8, test::num9>::value));

METAL_TEST_ASSERT((!and_t<test::num0>::value));
METAL_TEST_ASSERT((!and_t<test::num1, test::num0>::value));
METAL_TEST_ASSERT((!and_t<test::num1, test::num2, test::num0>::value));
METAL_TEST_ASSERT((!and_t<test::num1, test::num2, test::num3, test::num0>::value));
METAL_TEST_ASSERT((!and_t<test::num1, test::num2, test::num3, test::num4, test::num0>::value));
METAL_TEST_ASSERT((!and_t<test::num1, test::num2, test::num3, test::num4, test::num5, test::num0>::value));
METAL_TEST_ASSERT((!and_t<test::num1, test::num2, test::num3, test::num4, test::num5, test::num6, test::num0>::value));
METAL_TEST_ASSERT((!and_t<test::num1, test::num2, test::num3, test::num4, test::num5, test::num6, test::num7, test::num0>::value));
METAL_TEST_ASSERT((!and_t<test::num1, test::num2, test::num3, test::num4, test::num5, test::num6, test::num7, test::num8, test::num0>::value));
