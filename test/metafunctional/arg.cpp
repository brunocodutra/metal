// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/traits/is_evaluable.hpp>
#include <boost/mpl2/metafunctional/traits/is_function.hpp>
#include <boost/mpl2/metafunctional/traits/is_callable.hpp>

#include "test.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_function<arg<0>>>));
BOOST_MPL2_ASSERT((is_function<arg<1>>));
BOOST_MPL2_ASSERT((is_function<arg<2>>));
BOOST_MPL2_ASSERT((is_function<arg<3>>));
BOOST_MPL2_ASSERT((is_function<arg<4>>));

BOOST_MPL2_ASSERT((not_<is_callable<arg<0>, short, int, long, long long>>));
BOOST_MPL2_ASSERT((is_callable<arg<1>, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<arg<2>, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<arg<3>, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<arg<4>, short, int, long, long long>));

BOOST_MPL2_ASSERT((not_<is_callable<arg<0>>>));
BOOST_MPL2_ASSERT((not_<is_callable<arg<1>>>));
BOOST_MPL2_ASSERT((not_<is_callable<arg<2>, int>>));
BOOST_MPL2_ASSERT((not_<is_callable<arg<3>, int, long>>));
BOOST_MPL2_ASSERT((not_<is_callable<arg<4>, int, long, long long>>));

BOOST_MPL2_ASSERT((std::is_same<call<arg<1>, short, int, long, long long>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<call<arg<2>, short, int, long, long long>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<call<arg<3>, short, int, long, long long>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<call<arg<4>, short, int, long, long long>::type, long long>));


int main()
{
    return 0;
}
