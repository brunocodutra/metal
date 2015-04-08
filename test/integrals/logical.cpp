// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/integrals/logical.hpp>
#include <boost/mpl2/integrals/integer.hpp>
#include <boost/mpl2/integrals/comparison/equal_to.hpp>
#include <boost/mpl2/core/assert.hpp>

using namespace boost::mpl2;

struct undefined;
typedef long_<0> zero;
typedef ushort_<1> one;

BOOST_MPL2_ASSERT((or_<zero, one>));
BOOST_MPL2_ASSERT((or_<zero, zero, one>));
BOOST_MPL2_ASSERT((or_<zero, zero, zero, one>));
BOOST_MPL2_ASSERT((or_<zero, zero, zero, zero, one>));
BOOST_MPL2_ASSERT((or_<zero, zero, zero, zero, zero, one>));
BOOST_MPL2_ASSERT((or_<zero, zero, zero, zero, zero, zero, one>));
BOOST_MPL2_ASSERT((or_<zero, zero, zero, zero, zero, zero, zero, one>));

BOOST_MPL2_ASSERT((not_<or_<zero, zero> >));
BOOST_MPL2_ASSERT((not_<or_<zero, zero, zero> >));
BOOST_MPL2_ASSERT((not_<or_<zero, zero, zero, zero> >));
BOOST_MPL2_ASSERT((not_<or_<zero, zero, zero, zero, zero> >));
BOOST_MPL2_ASSERT((not_<or_<zero, zero, zero, zero, zero, zero> >));
BOOST_MPL2_ASSERT((not_<or_<zero, zero, zero, zero, zero, zero, zero> >));
BOOST_MPL2_ASSERT((not_<or_<zero, zero, zero, zero, zero, zero, zero, zero> >));

BOOST_MPL2_ASSERT((and_<one, one>));
BOOST_MPL2_ASSERT((and_<one, one, one>));
BOOST_MPL2_ASSERT((and_<one, one, one, one>));
BOOST_MPL2_ASSERT((and_<one, one, one, one, one>));
BOOST_MPL2_ASSERT((and_<one, one, one, one, one, one>));
BOOST_MPL2_ASSERT((and_<one, one, one, one, one, one, one>));
BOOST_MPL2_ASSERT((and_<one, one, one, one, one, one, one, one>));

BOOST_MPL2_ASSERT((not_<and_<one, zero> >));
BOOST_MPL2_ASSERT((not_<and_<one, one, zero> >));
BOOST_MPL2_ASSERT((not_<and_<one, one, one, zero> >));
BOOST_MPL2_ASSERT((not_<and_<one, one, one, one, zero> >));
BOOST_MPL2_ASSERT((not_<and_<one, one, one, one, one, zero> >));
BOOST_MPL2_ASSERT((not_<and_<one, one, one, one, one, one, zero> >));
BOOST_MPL2_ASSERT((not_<and_<one, one, one, one, one, one, one, zero> >));

BOOST_MPL2_ASSERT((or_<one, undefined>));
BOOST_MPL2_ASSERT((or_<one, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<one, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<one, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<one, undefined, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<one, undefined, undefined, undefined, undefined, undefined, undefined>));
BOOST_MPL2_ASSERT((or_<one, undefined, undefined, undefined, undefined, undefined, undefined, undefined>));

BOOST_MPL2_ASSERT((not_<and_<zero, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<zero, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<zero, undefined, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<zero, undefined, undefined, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<zero, undefined, undefined, undefined, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<zero, undefined, undefined, undefined, undefined, undefined, undefined> >));
BOOST_MPL2_ASSERT((not_<and_<zero, undefined, undefined, undefined, undefined, undefined, undefined, undefined> >));

BOOST_MPL2_ASSERT_EXPR((or_<zero, one>{}));
BOOST_MPL2_ASSERT_EXPR((and_<one, one>{}));
BOOST_MPL2_ASSERT_EXPR((not_<or_<zero, zero> >{}));

int main()
{
    return 0;
}
