// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/sequences/list.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using empty = list<>::type;
using single = list<void>::type;
using many = list<empty, int, void, single, float>::type;

BOOST_MPL2_ASSERT((std::is_same<many::at<std::integral_constant<std::size_t, 4>>::type, float>));
BOOST_MPL2_ASSERT((std::is_same<many::at<std::integral_constant<std::size_t, 3>>::type, single>));
BOOST_MPL2_ASSERT((std::is_same<many::at<std::integral_constant<std::size_t, 2>>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<many::at<std::integral_constant<std::size_t, 1>>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<many::at<std::integral_constant<std::size_t, 0>>::type, empty>));

BOOST_MPL2_ASSERT_EXPR(empty::size::value == 0);
BOOST_MPL2_ASSERT_EXPR(single::size::value == 1);
BOOST_MPL2_ASSERT_EXPR(many::size::value == 5);

int main()
{
    return 0;
}
