/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/call.hpp>

#include "test/functions.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace boost::metal;

namespace test
{
    using f0 = test::nullary<test::wrap>;
    using f1 = test::unary<test::wrap>;
    using f2 = test::binary<test::wrap>;
    using fn = test::n_ary<test::wrap>;
}

BOOST_METAL_ASSERT((std::is_same<call_t<test::f0>, test::f0::call<>::type>));
BOOST_METAL_ASSERT((std::is_same<call_t<test::f1, void>, test::f1::call<void>::type>));
BOOST_METAL_ASSERT((std::is_same<call_t<test::f2, void, void*>, test::f2::call<void, void*>::type>));

BOOST_METAL_ASSERT((std::is_same<call_t<test::fn>, test::fn::call<>::type>));
BOOST_METAL_ASSERT((std::is_same<call_t<test::fn, short>, test::fn::call<short>::type>));
BOOST_METAL_ASSERT((std::is_same<call_t<test::fn, short, int>, test::fn::call<short, int>::type>));
BOOST_METAL_ASSERT((std::is_same<call_t<test::fn, short, int, long>, test::fn::call<short, int, long>::type>));
BOOST_METAL_ASSERT((std::is_same<call_t<test::fn, short, int, long, long long>, test::fn::call<short, int, long, long long>::type>));
