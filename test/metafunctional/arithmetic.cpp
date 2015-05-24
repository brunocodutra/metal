// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/arithmetic.hpp>
#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/metafunctional/comparison/equal_to.hpp>
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

BOOST_MPL2_ASSERT_EXPR((inc<zero>{} == one{}));
BOOST_MPL2_ASSERT_EXPR((dec<zero>{} == negate<one>{}));
BOOST_MPL2_ASSERT_EXPR((inc<dec<one> >{} == one{}));
BOOST_MPL2_ASSERT_EXPR((inc<dec<one> >{} == dec<inc<one> >{}));
BOOST_MPL2_ASSERT_EXPR((negate<zero>{} == zero{}));
BOOST_MPL2_ASSERT_EXPR((inc<negate<one> >{} == zero{}));
BOOST_MPL2_ASSERT_EXPR((negate<negate<one> >{} == one{}));

BOOST_MPL2_ASSERT_EXPR((add<zero, one>{} == mul<one, one>{}));
BOOST_MPL2_ASSERT_EXPR((add<zero, one, two>{} == mul<one, three>{}));
BOOST_MPL2_ASSERT_EXPR((add<zero, one, two, three>{} == mul<two, three>{}));
BOOST_MPL2_ASSERT_EXPR((add<zero, one, two, three, four>{} == mul<two, five>{}));
BOOST_MPL2_ASSERT_EXPR((add<zero, one, two, three, four, five>{} == mul<three, five>{}));
BOOST_MPL2_ASSERT_EXPR((add<zero, one, two, three, four, five, six>{} == mul<three, seven>{}));
BOOST_MPL2_ASSERT_EXPR((add<zero, one, two, three, four, five, six, seven>{} == mul<four, seven>{}));

BOOST_MPL2_ASSERT_EXPR((sub<one, one>{} == zero{}));
BOOST_MPL2_ASSERT_EXPR((sub<two, one, one>{} == zero{}));
BOOST_MPL2_ASSERT_EXPR((sub<three, one, one, one>{} == zero{}));
BOOST_MPL2_ASSERT_EXPR((sub<four, one, one, one, one>{} == zero{}));
BOOST_MPL2_ASSERT_EXPR((sub<five, one, one, one, one, one>{} == zero{}));
BOOST_MPL2_ASSERT_EXPR((sub<six, one, one, one, one, one, one>{} == zero{}));
BOOST_MPL2_ASSERT_EXPR((sub<seven, one, one, one, one, one, one, one>{} == zero{}));

BOOST_MPL2_ASSERT_EXPR((mul<two, two>{} == int_<4>{}));
BOOST_MPL2_ASSERT_EXPR((mul<two, two, two>{} == int_<8>{}));
BOOST_MPL2_ASSERT_EXPR((mul<two, two, two, two>{} == int_<16>{}));
BOOST_MPL2_ASSERT_EXPR((mul<two, two, two, two, two>{} == int_<32>{}));
BOOST_MPL2_ASSERT_EXPR((mul<two, two, two, two, two, two>{} == int_<64>{}));
BOOST_MPL2_ASSERT_EXPR((mul<two, two, two, two, two, two, two>{} == int_<128>{}));
BOOST_MPL2_ASSERT_EXPR((mul<two, two, two, two, two, two, two, two>{} == int_<256>{}));

BOOST_MPL2_ASSERT_EXPR((div<int_<2>, two>{} == one{}));
BOOST_MPL2_ASSERT_EXPR((div<int_<4>, two, two>{} == one{}));
BOOST_MPL2_ASSERT_EXPR((div<int_<8>, two, two, two>{} == one{}));
BOOST_MPL2_ASSERT_EXPR((div<int_<16>, two, two, two, two>{} == one{}));
BOOST_MPL2_ASSERT_EXPR((div<int_<32>, two, two, two, two, two>{} == one{}));
BOOST_MPL2_ASSERT_EXPR((div<int_<64>, two, two, two, two, two, two>{} == one{}));
BOOST_MPL2_ASSERT_EXPR((div<int_<128>, two, two, two, two, two, two, two>{} == one{}));

int main()
{
    return 0;
}
