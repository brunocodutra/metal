// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/arithmetic.hpp>
#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/comparison/equal_to.hpp>
#include <boost/mpl2/core/assert.hpp>

using namespace boost::mpl2;

typedef short_<0> zero;
typedef int_<1> one;
typedef long_<2> two;
typedef long_long_<3> three;
typedef ushort_<4> four;
typedef uint_<5> five;
typedef ulong_<6> six;
typedef ulong_long_<7> seven;

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

BOOST_MPL2_ASSERT((equal_to<mul<two, two>, int_<4>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two>, int_<8>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two>, int_<16>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two, two>, int_<32>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two, two, two>, int_<64>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two, two, two, two>, int_<128>>));
BOOST_MPL2_ASSERT((equal_to<mul<two, two, two, two, two, two, two, two>, int_<256>>));

BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<int_<2>, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<int_<4>, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<int_<8>, two, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<int_<16>, two, two, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<int_<32>, two, two, two, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<int_<64>, two, two, two, two, two, two>, one>));
BOOST_MPL2_ASSERT((equal_to<boost::mpl2::div<int_<128>, two, two, two, two, two, two, two>, one>));

int main()
{
    return 0;
}
