// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/traits/is_callable.hpp>

#include "../test.hpp"

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_callable<> >));
BOOST_MPL2_ASSERT((not_<is_callable<void> >));
BOOST_MPL2_ASSERT((not_<is_callable<void, void*> >));

BOOST_MPL2_ASSERT((not_<is_callable<test::fundamental<> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::function<> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::incomplete<> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::empty<> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::eponym<> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::evaluable<> > >));

BOOST_MPL2_ASSERT((not_<is_callable<test::fundamental<>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::function<>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::incomplete<>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::empty<>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::eponym<>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::evaluable<>, void> >));

BOOST_MPL2_ASSERT((not_<is_callable<test::fundamental<>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::function<>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::incomplete<>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::empty<>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::eponym<>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::evaluable<>, void, void*> >));

BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::eponym> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::evaluable> > >));

BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::incomplete>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::empty>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::eponym>, void> >));
BOOST_MPL2_ASSERT((is_callable<test::unary<test::evaluable>, void>));

BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::incomplete>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::empty>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::eponym>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::unary<test::evaluable>, void, void*> >));

BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::eponym> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::evaluable> > >));

BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::incomplete>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::empty>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::eponym>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::evaluable>, void> >));

BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::incomplete>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::empty>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::binary<test::eponym>, void, void*> >));
BOOST_MPL2_ASSERT((is_callable<test::binary<test::evaluable>, void, void*>));

BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::eponym> > >));
BOOST_MPL2_ASSERT((is_callable<test::n_ary<test::evaluable> >));

BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::incomplete>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::empty>, void> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::eponym>, void> >));
BOOST_MPL2_ASSERT((is_callable<test::n_ary<test::evaluable>, void>));

BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::incomplete>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::empty>, void, void*> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::n_ary<test::eponym>, void, void*> >));
BOOST_MPL2_ASSERT((is_callable<test::n_ary<test::evaluable>, void, void*>));


int main()
{
    return 0;
}
