// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT(is_function<arg<1> >);
BOOST_MPL2_ASSERT(is_function<arg<2> >);
BOOST_MPL2_ASSERT(is_function<arg<3> >);
BOOST_MPL2_ASSERT(is_function<arg<4> >);

BOOST_MPL2_ASSERT((is_callable<arg<1>, short>));
BOOST_MPL2_ASSERT((is_callable<arg<2>, short, int>));
BOOST_MPL2_ASSERT((is_callable<arg<3>, short, int, long>));
BOOST_MPL2_ASSERT((is_callable<arg<4>, short, int, long, long long>));

BOOST_MPL2_ASSERT((std::is_same<call<arg<1>, short>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<call<arg<2>, short, int>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<call<arg<3>, short, int, long>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<call<arg<4>, short, int, long, long long>::type, long long>));

BOOST_MPL2_ASSERT((not_<is_callable<arg<1> > >));
BOOST_MPL2_ASSERT((not_<is_callable<arg<2>, int> >));
BOOST_MPL2_ASSERT((not_<is_callable<arg<3>, int, long> >));
BOOST_MPL2_ASSERT((not_<is_callable<arg<4>, int, long, long long> >));

int main()
{
    return 0;
}
