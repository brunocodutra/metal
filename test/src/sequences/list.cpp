// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/sequences/list.hpp>
#include <boost/mpl2/metafunctional/traits/is_evaluable.hpp>

#include "test/integrals.hpp"
#include "test/sequences.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_evaluable<test::none<list>::at, test::zero>>));
BOOST_MPL2_ASSERT((not_<is_evaluable<test::single<list>::at, test::one>>));
BOOST_MPL2_ASSERT((not_<is_evaluable<test::many<list>::at, test::ten>>));

BOOST_MPL2_ASSERT((std::is_same<test::single<list>::at<test::zero>::type, test::a>));

BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::zero>::type, test::a>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::one>::type, test::b>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::two>::type, test::c>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::three>::type, test::d>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::four>::type, test::e>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::five>::type, test::f>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::six>::type, test::g>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::seven>::type, test::h>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::eight>::type, test::i>));
BOOST_MPL2_ASSERT((std::is_same<test::many<list>::at<test::nine>::type, test::j>));

BOOST_MPL2_ASSERT((equal_to<test::none<list>::size, test::zero>));
BOOST_MPL2_ASSERT((equal_to<test::single<list>::size, test::one>));
BOOST_MPL2_ASSERT((equal_to<test::many<list>::size, test::ten>));
