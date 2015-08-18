// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/just.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_just_t<test::val0>::value));
METAL_TEST_ASSERT((!is_just_t<test::val1>::value));
METAL_TEST_ASSERT((!is_just_t<test::val2>::value));
METAL_TEST_ASSERT((!is_just_t<test::val3>::value));
METAL_TEST_ASSERT((!is_just_t<test::val4>::value));
METAL_TEST_ASSERT((!is_just_t<test::val5>::value));
METAL_TEST_ASSERT((!is_just_t<test::val6>::value));
METAL_TEST_ASSERT((!is_just_t<test::val7>::value));
METAL_TEST_ASSERT((!is_just_t<test::val8>::value));
METAL_TEST_ASSERT((!is_just_t<test::val9>::value));

METAL_TEST_ASSERT((is_just_t<test::num0>::value));
METAL_TEST_ASSERT((is_just_t<test::num1>::value));
METAL_TEST_ASSERT((is_just_t<test::num2>::value));
METAL_TEST_ASSERT((is_just_t<test::num3>::value));
METAL_TEST_ASSERT((is_just_t<test::num4>::value));
METAL_TEST_ASSERT((is_just_t<test::num5>::value));
METAL_TEST_ASSERT((is_just_t<test::num6>::value));
METAL_TEST_ASSERT((is_just_t<test::num7>::value));
METAL_TEST_ASSERT((is_just_t<test::num9>::value));
METAL_TEST_ASSERT((is_just_t<test::num9>::value));

METAL_TEST_ASSERT((is_just_t<just<test::val0>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val1>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val2>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val3>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val4>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val5>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val6>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val7>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val8>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::val9>>::value));

METAL_TEST_ASSERT((std::is_same<just<test::val0>::type, test::val0>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val1>::type, test::val1>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val2>::type, test::val2>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val3>::type, test::val3>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val4>::type, test::val4>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val5>::type, test::val5>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val6>::type, test::val6>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val7>::type, test::val7>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val8>::type, test::val8>::value));
METAL_TEST_ASSERT((std::is_same<just<test::val9>::type, test::val9>::value));
