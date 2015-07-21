// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/call.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((std::is_same<call_t<test::f0>, test::f0::call<>::type>::value));
METAL_TEST_ASSERT((std::is_same<call_t<test::f1, test::a1>, test::f1::call<test::a1>::type>::value));
METAL_TEST_ASSERT((std::is_same<call_t<test::f2, test::a1, test::a2>, test::f2::call<test::a1, test::a2>::type>::value));

METAL_TEST_ASSERT((std::is_same<call_t<test::fn>, test::fn::call<>::type>::value));
METAL_TEST_ASSERT((std::is_same<call_t<test::fn, test::a1>, test::fn::call<test::a1>::type>::value));
METAL_TEST_ASSERT((std::is_same<call_t<test::fn, test::a1, test::a2>, test::fn::call<test::a1, test::a2>::type>::value));
METAL_TEST_ASSERT((std::is_same<call_t<test::fn, test::a1, test::a2, test::a3>, test::fn::call<test::a1, test::a2, test::a3>::type>::value));
METAL_TEST_ASSERT((std::is_same<call_t<test::fn, test::a1, test::a2, test::a3, test::a4>, test::fn::call<test::a1, test::a2, test::a3, test::a4>::type>::value));
