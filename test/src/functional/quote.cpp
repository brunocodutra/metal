/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/quote.hpp>
#include <metal/functional/call.hpp>
#include <metal/functional/traits/is_function.hpp>
#include <metal/functional/traits/is_callable.hpp>

#include "test/expressions.hpp"
#include "test/main.hpp"

using namespace metal;

namespace test
{
    using q1 = quote<test::fundamental>;
    using q2 = quote<test::incomplete>;
    using q3 = quote<test::empty>;
    using q4 = quote<test::evaluable>;
    using q5 = quote<test::call>;
}

METAL_ASSERT((std::is_same<test::q1::type, test::q1>));
METAL_ASSERT((std::is_same<test::q2::type, test::q2>));
METAL_ASSERT((std::is_same<test::q3::type, test::q3>));
METAL_ASSERT((std::is_same<test::q4::type, test::q4>));

METAL_ASSERT((is_function<test::q1>));
METAL_ASSERT((is_function<test::q2>));
METAL_ASSERT((is_function<test::q3>));
METAL_ASSERT((is_function<test::q4>));
METAL_ASSERT((is_function<test::q5>));

METAL_ASSERT((not_<is_callable<test::q1>>));
METAL_ASSERT((not_<is_callable<test::q2>>));
METAL_ASSERT((not_<is_callable<test::q3>>));
METAL_ASSERT((is_callable<test::q4>));
METAL_ASSERT((not_<is_callable<test::q5>>));

METAL_ASSERT((std::is_same<call_t<test::q4>, test::q4::call<>::type>));
