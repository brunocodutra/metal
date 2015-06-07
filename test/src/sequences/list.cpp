// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/comparison/equal_to.hpp>
#include <boost/mpl2/sequences/list.hpp>

#include "test/integrals.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;

using empty = list<>::type;
using single = list<void>::type;
using many = list<empty, int, void, single, float>::type;

BOOST_MPL2_ASSERT((std::is_same<many::at<test::zero>::type, empty>));
BOOST_MPL2_ASSERT((std::is_same<many::at<test::one>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<many::at<test::two>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<many::at<test::three>::type, single>));
BOOST_MPL2_ASSERT((std::is_same<many::at<test::four>::type, float>));

BOOST_MPL2_ASSERT((equal_to<empty::size, test::zero>));
BOOST_MPL2_ASSERT((equal_to<single::size, test::one>));
BOOST_MPL2_ASSERT((equal_to<many::size, test::five>));
