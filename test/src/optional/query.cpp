// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/query.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!query_t<test::val0>::value));
METAL_TEST_ASSERT((!query_t<test::val1>::value));
METAL_TEST_ASSERT((!query_t<test::val2>::value));
METAL_TEST_ASSERT((!query_t<test::val3>::value));
METAL_TEST_ASSERT((!query_t<test::val4>::value));
METAL_TEST_ASSERT((!query_t<test::val5>::value));
METAL_TEST_ASSERT((!query_t<test::val6>::value));
METAL_TEST_ASSERT((!query_t<test::val7>::value));
METAL_TEST_ASSERT((!query_t<test::val8>::value));
METAL_TEST_ASSERT((!query_t<test::val9>::value));

METAL_TEST_ASSERT((!query_t<test::num0>::value));
METAL_TEST_ASSERT((query_t<test::num1>::value));
METAL_TEST_ASSERT((query_t<test::num2>::value));
METAL_TEST_ASSERT((query_t<test::num3>::value));
METAL_TEST_ASSERT((query_t<test::num4>::value));
METAL_TEST_ASSERT((query_t<test::num5>::value));
METAL_TEST_ASSERT((query_t<test::num6>::value));
METAL_TEST_ASSERT((query_t<test::num7>::value));
METAL_TEST_ASSERT((query_t<test::num8>::value));
METAL_TEST_ASSERT((query_t<test::num9>::value));

METAL_TEST_ASSERT((!query_t<just<test::num0>>::value));
METAL_TEST_ASSERT((query_t<just<test::num1>>::value));
METAL_TEST_ASSERT((query_t<just<test::num2>>::value));
METAL_TEST_ASSERT((query_t<just<test::num3>>::value));
METAL_TEST_ASSERT((query_t<just<test::num4>>::value));
METAL_TEST_ASSERT((query_t<just<test::num5>>::value));
METAL_TEST_ASSERT((query_t<just<test::num6>>::value));
METAL_TEST_ASSERT((query_t<just<test::num7>>::value));
METAL_TEST_ASSERT((query_t<just<test::num8>>::value));
METAL_TEST_ASSERT((query_t<just<test::num9>>::value));
