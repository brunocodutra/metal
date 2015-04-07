// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/arg.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((std::is_same<arg<1>::call<short, int, long, long long>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<arg<2>::call<short, int, long, long long>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<arg<3>::call<short, int, long, long long>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<arg<4>::call<short, int, long, long long>::type, long long>));

int main()
{
    return 0;
}
