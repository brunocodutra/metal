// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/traits/is_evaluable.hpp>
#include <boost/metal/functional/traits/is_function.hpp>
#include <boost/metal/functional/traits/is_callable.hpp>

#include "test/types.hpp"
#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((not_<is_function<arg<0>>>));
BOOST_METAL_ASSERT((is_function<arg<1>>));
BOOST_METAL_ASSERT((is_function<arg<2>>));
BOOST_METAL_ASSERT((is_function<arg<3>>));
BOOST_METAL_ASSERT((is_function<arg<4>>));

BOOST_METAL_ASSERT((not_<is_callable<arg<0>, test::a, test::b, test::c, test::d>>));
BOOST_METAL_ASSERT((is_callable<arg<1>, test::a, test::b, test::c, test::d>));
BOOST_METAL_ASSERT((is_callable<arg<2>, test::a, test::b, test::c, test::d>));
BOOST_METAL_ASSERT((is_callable<arg<3>, test::a, test::b, test::c, test::d>));
BOOST_METAL_ASSERT((is_callable<arg<4>, test::a, test::b, test::c, test::d>));

BOOST_METAL_ASSERT((not_<is_callable<arg<0>>>));
BOOST_METAL_ASSERT((not_<is_callable<arg<1>>>));
BOOST_METAL_ASSERT((not_<is_callable<arg<2>, test::b>>));
BOOST_METAL_ASSERT((not_<is_callable<arg<3>, test::b, test::c>>));
BOOST_METAL_ASSERT((not_<is_callable<arg<4>, test::b, test::c, test::d>>));

BOOST_METAL_ASSERT((std::is_same<call_t<arg<1>, test::a, test::b, test::c, test::d>, test::a>));
BOOST_METAL_ASSERT((std::is_same<call_t<arg<2>, test::a, test::b, test::c, test::d>, test::b>));
BOOST_METAL_ASSERT((std::is_same<call_t<arg<3>, test::a, test::b, test::c, test::d>, test::c>));
BOOST_METAL_ASSERT((std::is_same<call_t<arg<4>, test::a, test::b, test::c, test::d>, test::d>));
