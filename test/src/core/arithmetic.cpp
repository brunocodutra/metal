// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/arithmetic.hpp>

#include "test/integrals.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((equal_to<inc<test::zero>, test::one>));
BOOST_MPL2_ASSERT((equal_to<dec<test::zero>, neg<test::one>>));
BOOST_MPL2_ASSERT((equal_to<inc<dec<test::one>>, test::one>));
BOOST_MPL2_ASSERT((equal_to<inc<dec<test::one>>, dec<inc<test::one>>>));
BOOST_MPL2_ASSERT((equal_to<neg<test::zero>, test::zero>));
BOOST_MPL2_ASSERT((equal_to<inc<neg<test::one>>, test::zero>));
BOOST_MPL2_ASSERT((equal_to<neg<neg<test::one>>, test::one>));

BOOST_MPL2_ASSERT((equal_to<add<test::zero, test::one>, mul<test::one, test::one>>));
BOOST_MPL2_ASSERT((equal_to<add<test::zero, test::one, test::two>, mul<test::one, test::three>>));
BOOST_MPL2_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three>, mul<test::two, test::three>>));
BOOST_MPL2_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three, test::four>, mul<test::two, test::five>>));
BOOST_MPL2_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three, test::four, test::five>, mul<test::three, test::five>>));
BOOST_MPL2_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three, test::four, test::five, test::six>, mul<test::three, test::seven>>));
BOOST_MPL2_ASSERT((equal_to<add<test::zero, test::one, test::two, test::three, test::four, test::five, test::six, test::seven>, mul<test::four, test::seven>>));

BOOST_MPL2_ASSERT((equal_to<sub<test::one, test::one>, test::zero>));
BOOST_MPL2_ASSERT((equal_to<sub<test::two, test::one, test::one>, test::zero>));
BOOST_MPL2_ASSERT((equal_to<sub<test::three, test::one, test::one, test::one>, test::zero>));
BOOST_MPL2_ASSERT((equal_to<sub<test::four, test::one, test::one, test::one, test::one>, test::zero>));
BOOST_MPL2_ASSERT((equal_to<sub<test::five, test::one, test::one, test::one, test::one, test::one>, test::zero>));
BOOST_MPL2_ASSERT((equal_to<sub<test::six, test::one, test::one, test::one, test::one, test::one, test::one>, test::zero>));
BOOST_MPL2_ASSERT((equal_to<sub<test::seven, test::one, test::one, test::one, test::one, test::one, test::one, test::one>, test::zero>));

BOOST_MPL2_ASSERT((equal_to<mul<test::two, test::two>, std::integral_constant<int, 4>>));
BOOST_MPL2_ASSERT((equal_to<mul<test::two, test::two, test::two>, std::integral_constant<int, 8>>));
BOOST_MPL2_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two>, std::integral_constant<int, 16>>));
BOOST_MPL2_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two, test::two>, std::integral_constant<int, 32>>));
BOOST_MPL2_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two, test::two, test::two>, std::integral_constant<int, 64>>));
BOOST_MPL2_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two, test::two, test::two, test::two>, std::integral_constant<int, 128>>));
BOOST_MPL2_ASSERT((equal_to<mul<test::two, test::two, test::two, test::two, test::two, test::two, test::two, test::two>, std::integral_constant<int, 256>>));

BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 2>, test::two>, test::one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 4>, test::two, test::two>, test::one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 8>, test::two, test::two, test::two>, test::one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 16>, test::two, test::two, test::two, test::two>, test::one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 32>, test::two, test::two, test::two, test::two, test::two>, test::one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 64>, test::two, test::two, test::two, test::two, test::two, test::two>, test::one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 128>, test::two, test::two, test::two, test::two, test::two, test::two, test::two>, test::one>));
