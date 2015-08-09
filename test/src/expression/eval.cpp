// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/expression/eval.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_just<eval<test::empty>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr0>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::expr1>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::expr2>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr>>::value));

METAL_TEST_ASSERT((!is_just<eval<test::empty, test::val0>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::expr0, test::val0>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr1, test::val0>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::expr2, test::val0>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr, test::val0>>::value));

METAL_TEST_ASSERT((!is_just<eval<test::empty, test::val0, test::val1>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::expr0, test::val0, test::val1>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::expr1, test::val0, test::val1>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr2, test::val0, test::val1>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr, test::val0, test::val1>>::value));

METAL_TEST_ASSERT((std::is_same<eval_t<test::expr0>, test::expr0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr1, test::val0>, test::expr1<test::val0>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr2, test::val0, test::val1>, test::expr2<test::val0, test::val1>::type>::value));

METAL_TEST_ASSERT((std::is_same<eval_t<test::expr>, test::expr<>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr, test::val0>, test::expr<test::val0>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr, test::val0, test::val1>, test::expr<test::val0, test::val1>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr, test::val0, test::val1, test::val2>, test::expr<test::val0, test::val1, test::val2>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr, test::val0, test::val1, test::val2, test::val3>, test::expr<test::val0, test::val1, test::val2, test::val3>::type>::value));
