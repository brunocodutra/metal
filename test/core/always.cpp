// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/always.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using boost::mpl2::always;

struct x;

BOOST_MPL2_ASSERT((std::is_same<always<x>::type<>::type, x>));
BOOST_MPL2_ASSERT((std::is_same<always<x>::type<short>::type, x>));
BOOST_MPL2_ASSERT((std::is_same<always<x>::type<short, int>::type, x>));
BOOST_MPL2_ASSERT((std::is_same<always<x>::type<short, int, long>::type, x>));
BOOST_MPL2_ASSERT((std::is_same<always<x>::type<short, int, long, long long>::type, x>));

int main()
{
    return 0;
}
