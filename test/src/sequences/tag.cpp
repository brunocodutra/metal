// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/sequences/tag.hpp>

#include "test/main.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((std::is_same<tag<test::fundamental<>>::type, tag<test::fundamental<>>>));
BOOST_MPL2_ASSERT((std::is_same<tag<test::function<>>::type, tag<test::function<>>>));
BOOST_MPL2_ASSERT((std::is_same<tag<test::incomplete<>>::type, tag<test::incomplete<>>>));
BOOST_MPL2_ASSERT((std::is_same<tag<test::tagged<>>::type, test::tagged<>::tag>));
BOOST_MPL2_ASSERT((std::is_same<tag<test::eponym<test::tag>>::type, test::tag<>>));
