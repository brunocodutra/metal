// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/algorithm/list.hpp>
#include <boost/metal/functional/traits/is_evaluable.hpp>

#include "test/integrals.hpp"
#include "test/containers.hpp"
#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((not_<is_evaluable<test::none<list>::at, test::zero>>));
BOOST_METAL_ASSERT((not_<is_evaluable<test::single<list>::at, test::one>>));
BOOST_METAL_ASSERT((not_<is_evaluable<test::many<list>::at, test::ten>>));

BOOST_METAL_ASSERT((std::is_same<test::single<list>::at<test::zero>::type, test::a>));

BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::zero>::type, test::a>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::one>::type, test::b>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::two>::type, test::c>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::three>::type, test::d>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::four>::type, test::e>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::five>::type, test::f>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::six>::type, test::g>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::seven>::type, test::h>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::eight>::type, test::i>));
BOOST_METAL_ASSERT((std::is_same<test::many<list>::at<test::nine>::type, test::j>));

BOOST_METAL_ASSERT((equal_to<test::none<list>::size, test::zero>));
BOOST_METAL_ASSERT((equal_to<test::single<list>::size, test::one>));
BOOST_METAL_ASSERT((equal_to<test::many<list>::size, test::ten>));
