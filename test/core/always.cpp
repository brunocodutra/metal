// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/always.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((std::is_same<always<void>::call<>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<always<void>::call<short>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<always<void>::call<short, int>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<always<void>::call<short, int, long>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<always<void>::call<short, int, long, long long>::type, void>));

int main()
{
    return 0;
}
