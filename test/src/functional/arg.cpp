/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/traits/is_evaluable.hpp>
#include <boost/metal/functional/traits/is_function.hpp>
#include <boost/metal/functional/traits/is_callable.hpp>

#include "test/types.hpp"
#include "test/main.hpp"

using namespace boost::metal;
using namespace boost::metal::placeholders;

BOOST_METAL_ASSERT((std::is_same<_0::type, _0>));
BOOST_METAL_ASSERT((std::is_same<_1::type, _1>));
BOOST_METAL_ASSERT((std::is_same<_2::type, _2>));
BOOST_METAL_ASSERT((std::is_same<_3::type, _3>));
BOOST_METAL_ASSERT((std::is_same<_4::type, _4>));
BOOST_METAL_ASSERT((std::is_same<_5::type, _5>));
BOOST_METAL_ASSERT((std::is_same<_6::type, _6>));
BOOST_METAL_ASSERT((std::is_same<_7::type, _7>));
BOOST_METAL_ASSERT((std::is_same<_8::type, _8>));
BOOST_METAL_ASSERT((std::is_same<_9::type, _9>));

BOOST_METAL_ASSERT((not_<is_function<_0>>));
BOOST_METAL_ASSERT((is_function<_1>));
BOOST_METAL_ASSERT((is_function<_2>));
BOOST_METAL_ASSERT((is_function<_3>));
BOOST_METAL_ASSERT((is_function<_4>));

BOOST_METAL_ASSERT((not_<is_callable<_0, test::a, test::b, test::c, test::d>>));
BOOST_METAL_ASSERT((is_callable<_1, test::a, test::b, test::c, test::d>));
BOOST_METAL_ASSERT((is_callable<_2, test::a, test::b, test::c, test::d>));
BOOST_METAL_ASSERT((is_callable<_3, test::a, test::b, test::c, test::d>));
BOOST_METAL_ASSERT((is_callable<_4, test::a, test::b, test::c, test::d>));

BOOST_METAL_ASSERT((not_<is_callable<_0>>));
BOOST_METAL_ASSERT((not_<is_callable<_1>>));
BOOST_METAL_ASSERT((not_<is_callable<_2, test::b>>));
BOOST_METAL_ASSERT((not_<is_callable<_3, test::b, test::c>>));
BOOST_METAL_ASSERT((not_<is_callable<_4, test::b, test::c, test::d>>));

BOOST_METAL_ASSERT((std::is_same<call_t<_1, test::a, test::b, test::c, test::d>, test::a>));
BOOST_METAL_ASSERT((std::is_same<call_t<_2, test::a, test::b, test::c, test::d>, test::b>));
BOOST_METAL_ASSERT((std::is_same<call_t<_3, test::a, test::b, test::c, test::d>, test::c>));
BOOST_METAL_ASSERT((std::is_same<call_t<_4, test::a, test::b, test::c, test::d>, test::d>));
