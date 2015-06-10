/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/arg.hpp>
#include <boost/metal/functional/call.hpp>
#include <boost/metal/functional/traits/is_evaluable.hpp>
#include <boost/metal/functional/traits/is_function.hpp>
#include <boost/metal/functional/traits/is_callable.hpp>

#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((not_<is_function<arg<0>>>));
BOOST_METAL_ASSERT((is_function<arg<1>>));
BOOST_METAL_ASSERT((is_function<arg<2>>));
BOOST_METAL_ASSERT((is_function<arg<3>>));
BOOST_METAL_ASSERT((is_function<arg<4>>));

BOOST_METAL_ASSERT((not_<is_callable<arg<0>, short, int, long, long long>>));
BOOST_METAL_ASSERT((is_callable<arg<1>, short, int, long, long long>));
BOOST_METAL_ASSERT((is_callable<arg<2>, short, int, long, long long>));
BOOST_METAL_ASSERT((is_callable<arg<3>, short, int, long, long long>));
BOOST_METAL_ASSERT((is_callable<arg<4>, short, int, long, long long>));

BOOST_METAL_ASSERT((not_<is_callable<arg<0>>>));
BOOST_METAL_ASSERT((not_<is_callable<arg<1>>>));
BOOST_METAL_ASSERT((not_<is_callable<arg<2>, int>>));
BOOST_METAL_ASSERT((not_<is_callable<arg<3>, int, long>>));
BOOST_METAL_ASSERT((not_<is_callable<arg<4>, int, long, long long>>));

BOOST_METAL_ASSERT((std::is_same<call_t<arg<1>, short, int, long, long long>, short>));
BOOST_METAL_ASSERT((std::is_same<call_t<arg<2>, short, int, long, long long>, int>));
BOOST_METAL_ASSERT((std::is_same<call_t<arg<3>, short, int, long, long long>, long>));
BOOST_METAL_ASSERT((std::is_same<call_t<arg<4>, short, int, long, long long>, long long>));
