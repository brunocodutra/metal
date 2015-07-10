// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/call.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

METAL_ASSERT((std::is_same<call_t<test::f0>, test::f0::call<>::type>));
METAL_ASSERT((std::is_same<call_t<test::f1, test::a0>, test::f1::call<test::a0>::type>));
METAL_ASSERT((std::is_same<call_t<test::f2, test::a0, test::a1>, test::f2::call<test::a0, test::a1>::type>));

METAL_ASSERT((std::is_same<call_t<test::fn>, test::fn::call<>::type>));
METAL_ASSERT((std::is_same<call_t<test::fn, test::a0>, test::fn::call<test::a0>::type>));
METAL_ASSERT((std::is_same<call_t<test::fn, test::a0, test::a1>, test::fn::call<test::a0, test::a1>::type>));
METAL_ASSERT((std::is_same<call_t<test::fn, test::a0, test::a1, test::a2>, test::fn::call<test::a0, test::a1, test::a2>::type>));
METAL_ASSERT((std::is_same<call_t<test::fn, test::a0, test::a1, test::a2, test::a3>, test::fn::call<test::a0, test::a1, test::a2, test::a3>::type>));
