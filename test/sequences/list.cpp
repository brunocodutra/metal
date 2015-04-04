// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/integrals/size_t.hpp>
#include <boost/mpl2/core/assert.hpp>
#include <boost/mpl2/sequences/list.hpp>

#include <type_traits>

using boost::mpl2::list;
using boost::mpl2::size_t_;

typedef list<>::type empty;
typedef list<void>::type single;
typedef list<empty, int, void, single, float>::type many;

BOOST_MPL2_ASSERT((std::is_same<many::at<size_t_<0> >::type, float>));
BOOST_MPL2_ASSERT((std::is_same<many::at<size_t_<1> >::type, single>));
BOOST_MPL2_ASSERT((std::is_same<many::at<size_t_<2> >::type, void>));
BOOST_MPL2_ASSERT((std::is_same<many::at<size_t_<3> >::type, int>));
BOOST_MPL2_ASSERT((std::is_same<many::at<size_t_<4> >::type, empty>));

BOOST_MPL2_ASSERT_EXPR(empty::size{} == 0);
BOOST_MPL2_ASSERT_EXPR(single::size{} == 1);
BOOST_MPL2_ASSERT_EXPR(many::size{} == 5);

int main()
{
    return 0;
}
