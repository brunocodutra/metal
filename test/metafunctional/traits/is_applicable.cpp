// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/traits/is_applicable.hpp>

#include "../test.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_applicable<> >));
BOOST_MPL2_ASSERT((is_applicable<void>));
BOOST_MPL2_ASSERT((is_applicable<void, void*>));

BOOST_MPL2_ASSERT((is_applicable<test::fundamental<> >));
BOOST_MPL2_ASSERT((is_applicable<test::function<> >));
BOOST_MPL2_ASSERT((is_applicable<test::incomplete<> >));
BOOST_MPL2_ASSERT((is_applicable<test::empty<> >));
BOOST_MPL2_ASSERT((is_applicable<test::eponym<> >));
BOOST_MPL2_ASSERT((is_applicable<test::evaluable<> >));

BOOST_MPL2_ASSERT((is_applicable<test::fundamental<>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::function<>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::incomplete<>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::empty<>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::eponym<>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::evaluable<>, void>));

BOOST_MPL2_ASSERT((is_applicable<test::fundamental<>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::function<>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::incomplete<>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::empty<>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::eponym<>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::evaluable<>, void, void*>));

BOOST_MPL2_ASSERT((is_applicable<test::unary<test::incomplete> >));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::empty> >));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::eponym> >));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::evaluable> >));

BOOST_MPL2_ASSERT((is_applicable<test::unary<test::incomplete>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::empty>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::eponym>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::evaluable>, void>));

BOOST_MPL2_ASSERT((is_applicable<test::unary<test::incomplete>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::empty>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::eponym>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::unary<test::evaluable>, void, void*>));

BOOST_MPL2_ASSERT((is_applicable<test::binary<test::incomplete> >));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::empty> >));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::eponym> >));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::evaluable> >));

BOOST_MPL2_ASSERT((is_applicable<test::binary<test::incomplete>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::empty>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::eponym>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::evaluable>, void>));

BOOST_MPL2_ASSERT((is_applicable<test::binary<test::incomplete>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::empty>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::eponym>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::binary<test::evaluable>, void, void*>));

BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::incomplete> >));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::empty> >));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::eponym> >));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::evaluable> >));

BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::incomplete>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::empty>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::eponym>, void>));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::evaluable>, void>));

BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::incomplete>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::empty>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::eponym>, void, void*>));
BOOST_MPL2_ASSERT((is_applicable<test::n_ary<test::evaluable>, void, void*>));

int main()
{
    return 0;
}
