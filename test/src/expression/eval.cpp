// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/expression/eval.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((!is_just<eval<test::empty>>::value));
METAL_TEST_ASSERT((is_just<eval<test::e0>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::e1>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::e2>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr>>::value));

METAL_TEST_ASSERT((!is_just<eval<test::empty, test::v0>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::e0, test::v0>>::value));
METAL_TEST_ASSERT((is_just<eval<test::e1, test::v0>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::e2, test::v0>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr, test::v0>>::value));

METAL_TEST_ASSERT((!is_just<eval<test::empty, test::v0, test::v1>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::e0, test::v0, test::v1>>::value));
METAL_TEST_ASSERT((!is_just<eval<test::e1, test::v0, test::v1>>::value));
METAL_TEST_ASSERT((is_just<eval<test::e2, test::v0, test::v1>>::value));
METAL_TEST_ASSERT((is_just<eval<test::expr, test::v0, test::v1>>::value));

METAL_TEST_ASSERT((std::is_same<eval_t<test::e0>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::e1, test::v0>, test::e1<test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::e2, test::v0, test::v1>, test::e2<test::v0, test::v1>::type>::value));

METAL_TEST_ASSERT((std::is_same<eval_t<test::expr>, test::expr<>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr, test::v0>, test::expr<test::v0>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr, test::v0, test::v1>, test::expr<test::v0, test::v1>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr, test::v0, test::v1, test::v2>, test::expr<test::v0, test::v1, test::v2>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::expr, test::v0, test::v1, test::v2, test::v3>, test::expr<test::v0, test::v1, test::v2, test::v3>::type>::value));
