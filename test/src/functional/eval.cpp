// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/eval.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((std::is_same<eval_t<test::e0>, test::e0<>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::e1, test::a0>, test::e1<test::a0>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::e2, test::a0, test::a1>, test::e2<test::a0, test::a1>::type>::value));

METAL_TEST_ASSERT((std::is_same<eval_t<test::en>, test::en<>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::en, test::a0>, test::en<test::a0>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::en, test::a0, test::a1>, test::en<test::a0, test::a1>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::en, test::a0, test::a1, test::a2>, test::en<test::a0, test::a1, test::a2>::type>::value));
METAL_TEST_ASSERT((std::is_same<eval_t<test::en, test::a0, test::a1, test::a2, test::a3>, test::en<test::a0, test::a1, test::a2, test::a3>::type>::value));
