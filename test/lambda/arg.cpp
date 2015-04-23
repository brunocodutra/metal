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

BOOST_MPL2_ASSERT(is_function<_>);
BOOST_MPL2_ASSERT(is_function<_1>);
BOOST_MPL2_ASSERT(is_function<_2>);
BOOST_MPL2_ASSERT(is_function<_3>);
BOOST_MPL2_ASSERT(is_function<_4>);

BOOST_MPL2_ASSERT((is_callable<_, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<_1, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<_2, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<_3, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_callable<_4, short, int, long, long long>));

BOOST_MPL2_ASSERT((is_callable<_>));
BOOST_MPL2_ASSERT((not_<is_callable<_1> >));
BOOST_MPL2_ASSERT((not_<is_callable<_2, int> >));
BOOST_MPL2_ASSERT((not_<is_callable<_3, int, long> >));
BOOST_MPL2_ASSERT((not_<is_callable<_4, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<call<_>::type, pack<> >));
//BOOST_MPL2_ASSERT((std::is_same<call<_, short>::type, pack<short> >));
//BOOST_MPL2_ASSERT((std::is_same<call<_, short, int>::type, pack<short, int> >));
//BOOST_MPL2_ASSERT((std::is_same<call<_, short, int, long>::type, pack<short, int, long> >));
//BOOST_MPL2_ASSERT((std::is_same<call<_, short, int, long, long long>::type, pack<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<call<_1, short, int, long, long long>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<call<_2, short, int, long, long long>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<call<_3, short, int, long, long long>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<call<_4, short, int, long, long long>::type, long long>));

int main()
{
    return 0;
}
