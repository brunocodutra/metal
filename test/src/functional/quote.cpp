// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/quote.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/traits/is_function.hpp>
#include <boost/metal/functional/traits/is_callable.hpp>

#include "test/expressions.hpp"
#include "test/main.hpp"

using namespace boost::metal;

namespace test
{
    using q1 = quote<test::fundamental>;
    using q2 = quote<test::incomplete>;
    using q3 = quote<test::empty>;
    using q4 = quote<test::evaluable>;
    using q5 = quote<test::call>;
}

BOOST_METAL_ASSERT((is_function<test::q1>));
BOOST_METAL_ASSERT((is_function<test::q2>));
BOOST_METAL_ASSERT((is_function<test::q3>));
BOOST_METAL_ASSERT((is_function<test::q4>));
BOOST_METAL_ASSERT((is_function<test::q5>));

BOOST_METAL_ASSERT((not_<is_callable<test::q1>>));
BOOST_METAL_ASSERT((not_<is_callable<test::q2>>));
BOOST_METAL_ASSERT((not_<is_callable<test::q3>>));
BOOST_METAL_ASSERT((is_callable<test::q4>));
BOOST_METAL_ASSERT((not_<is_callable<test::q5>>));

BOOST_METAL_ASSERT((std::is_same<call_t<test::q4>, test::q4::call<>::type>));
