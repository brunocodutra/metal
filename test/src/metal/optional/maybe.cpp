// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/maybe.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((is_nothing_t<maybe<test::val0>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val1>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val2>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val3>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val4>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val5>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val6>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val7>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val8>>::value));
METAL_TEST_ASSERT((is_nothing_t<maybe<test::val9>>::value));

METAL_TEST_ASSERT((is_just_t<maybe<test::num0>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num1>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num2>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num3>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num4>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num5>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num6>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num7>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num9>>::value));
METAL_TEST_ASSERT((is_just_t<maybe<test::num9>>::value));

METAL_TEST_ASSERT((std::is_same<maybe<test::num0>::type, test::num0>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num1>::type, test::num1>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num2>::type, test::num2>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num3>::type, test::num3>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num4>::type, test::num4>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num5>::type, test::num5>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num6>::type, test::num6>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num7>::type, test::num7>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num8>::type, test::num8>::value));
METAL_TEST_ASSERT((std::is_same<maybe<test::num9>::type, test::num9>::value));
