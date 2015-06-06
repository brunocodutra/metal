// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/arithmetic.hpp>
#include <boost/mpl2/core/comparison/equal_to.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

typedef std::integral_constant<short, 0> zero;
typedef std::integral_constant<int, 1> one;
typedef std::integral_constant<long, 2> two;
typedef std::integral_constant<long long, 3> three;
typedef std::integral_constant<unsigned short, 4> four;
typedef std::integral_constant<unsigned int, 5> five;
typedef std::integral_constant<unsigned long, 6> six;
typedef std::integral_constant<unsigned long long, 7> seven;

BOOST_MPL2_ASSERT((equal_to<inc<zero>, one>));
BOOST_MPL2_ASSERT((equal_to<dec<zero>, neg<one>>));
BOOST_MPL2_ASSERT((equal_to<inc<dec<one> >, one>));
BOOST_MPL2_ASSERT((equal_to<inc<dec<one> >, dec<inc<one> >>));
BOOST_MPL2_ASSERT((equal_to<neg<zero>, zero>));
BOOST_MPL2_ASSERT((equal_to<inc<neg<one> >, zero>));
BOOST_MPL2_ASSERT((equal_to<neg<neg<one> >, one>));

BOOST_MPL2_ASSERT((equal_to<add<zero, one>, mul<one, one>>));
BOOST_MPL2_ASSERT((equal_to<add<zero, one, two>, mul<one, three>>));
BOOST_MPL2_ASSERT((equal_to<add<zero, one, two, three>, mul<two, three>>));
BOOST_MPL2_ASSERT((equal_to<add<zero, one, two, three, four>, mul<two, five>>));
BOOST_MPL2_ASSERT((equal_to<add<zero, one, two, three, four, five>, mul<three, five>>));
BOOST_MPL2_ASSERT((equal_to<add<zero, one, two, three, four, five, six>, mul<three, seven>>));
BOOST_MPL2_ASSERT((equal_to<add<zero, one, two, three, four, five, six, seven>, mul<four, seven>>));

BOOST_MPL2_ASSERT((equal_to<sub<one, one>, zero>));
BOOST_MPL2_ASSERT((equal_to<sub<two, one, one>, zero>));
BOOST_MPL2_ASSERT((equal_to<sub<three, one, one, one>, zero>));
BOOST_MPL2_ASSERT((equal_to<sub<four, one, one, one, one>, zero>));
BOOST_MPL2_ASSERT((equal_to<sub<five, one, one, one, one, one>, zero>));
BOOST_MPL2_ASSERT((equal_to<sub<six, one, one, one, one, one, one>, zero>));
BOOST_MPL2_ASSERT((equal_to<sub<seven, one, one, one, one, one, one, one>, zero>));

BOOST_MPL2_ASSERT((equal_to<mul<two, two>, std::integral_constant<int, 4>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two>, std::integral_constant<int, 8>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two>, std::integral_constant<int, 16>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two, two>, std::integral_constant<int, 32>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two, two, two>, std::integral_constant<int, 64>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two, two, two, two>, std::integral_constant<int, 128>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two, two, two, two, two>, std::integral_constant<int, 256>>));

BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 2>, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 4>, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 8>, two, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 16>, two, two, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 32>, two, two, two, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 64>, two, two, two, two, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<std::integral_constant<int, 128>, two, two, two, two, two, two, two>, one>));

int main()
{
    return 0;
}
