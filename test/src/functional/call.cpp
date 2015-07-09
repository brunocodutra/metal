// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/call.hpp>

#include "test/values.hpp"
#include "test/functions.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace metal;

namespace test
{
    using f0 = test::nullary<test::wrap>;
    using f1 = test::unary<test::wrap>;
    using f2 = test::binary<test::wrap>;
    using fn = test::n_ary<test::wrap>;
}

METAL_ASSERT((std::is_same<call_t<test::f0>, test::f0::call<>::type>));
METAL_ASSERT((std::is_same<call_t<test::f1, test::a>, test::f1::call<test::a>::type>));
METAL_ASSERT((std::is_same<call_t<test::f2, test::a, test::b>, test::f2::call<test::a, test::b>::type>));

METAL_ASSERT((std::is_same<call_t<test::fn>, test::fn::call<>::type>));
METAL_ASSERT((std::is_same<call_t<test::fn, test::a>, test::fn::call<test::a>::type>));
METAL_ASSERT((std::is_same<call_t<test::fn, test::a, test::b>, test::fn::call<test::a, test::b>::type>));
METAL_ASSERT((std::is_same<call_t<test::fn, test::a, test::b, test::c>, test::fn::call<test::a, test::b, test::c>::type>));
METAL_ASSERT((std::is_same<call_t<test::fn, test::a, test::b, test::c, test::d>, test::fn::call<test::a, test::b, test::c, test::d>::type>));
