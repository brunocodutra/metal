// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/traits.hpp>
#include <boost/mpl2/core/logical/not.hpp>

#include "test.hpp"

using namespace boost::mpl2;

template<typename c>
struct oneary
{
    template<typename>
    struct call : c {};
};

template<>
struct oneary<test::incomplete>
{
    template<typename>
    struct call;
};

template<typename c>
struct nullary
{
    template<typename = void>
    struct call : c {};
};

template<>
struct nullary<test::incomplete>
{
    template<typename = void>
    struct call;
};

BOOST_MPL2_ASSERT((not_<is_evaluable<test::fundamental> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<test::function> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<test::incomplete> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<test::empty> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<test::eponym> >));
BOOST_MPL2_ASSERT((is_evaluable<test::evaluable>));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary<test::eponym> > >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary<test::evaluable> > >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary<test::eponym> > >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary<test::evaluable> > >));

BOOST_MPL2_ASSERT((not_<is_function<test::fundamental> >));
BOOST_MPL2_ASSERT((not_<is_function<test::function> >));
BOOST_MPL2_ASSERT((not_<is_function<test::incomplete> >));
BOOST_MPL2_ASSERT((not_<is_function<test::empty> >));
BOOST_MPL2_ASSERT((not_<is_function<test::eponym> >));
BOOST_MPL2_ASSERT((not_<is_function<test::evaluable> >));
BOOST_MPL2_ASSERT((is_function<oneary<test::incomplete> >));
BOOST_MPL2_ASSERT((is_function<oneary<test::empty> >));
BOOST_MPL2_ASSERT((is_function<oneary<test::eponym> >));
BOOST_MPL2_ASSERT((is_function<oneary<test::evaluable> >));
BOOST_MPL2_ASSERT((is_function<nullary<test::incomplete> >));
BOOST_MPL2_ASSERT((is_function<nullary<test::empty> >));
BOOST_MPL2_ASSERT((is_function<nullary<test::eponym> >));
BOOST_MPL2_ASSERT((is_function<nullary<test::evaluable> >));

BOOST_MPL2_ASSERT((not_<is_callable<> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::fundamental> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::function> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::incomplete> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::empty> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::eponym> >));
BOOST_MPL2_ASSERT((not_<is_callable<test::evaluable> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary<test::eponym> > >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary<test::evaluable> > >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary<test::eponym> > >));
BOOST_MPL2_ASSERT((is_callable<nullary<test::evaluable> >));

BOOST_MPL2_ASSERT((not_<is_applicable<> >));
BOOST_MPL2_ASSERT((is_applicable<test::fundamental>));
BOOST_MPL2_ASSERT((is_applicable<test::function>));
BOOST_MPL2_ASSERT((is_applicable<test::incomplete>));
BOOST_MPL2_ASSERT((is_applicable<test::empty>));
BOOST_MPL2_ASSERT((is_applicable<test::eponym>));
BOOST_MPL2_ASSERT((is_applicable<test::evaluable>));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary<test::eponym> > >));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary<test::evaluable> > >));
BOOST_MPL2_ASSERT((not_<is_applicable<nullary<test::incomplete> > >));
BOOST_MPL2_ASSERT((not_<is_applicable<nullary<test::empty> > >));
BOOST_MPL2_ASSERT((not_<is_applicable<nullary<test::eponym> > >));
BOOST_MPL2_ASSERT((is_applicable<nullary<test::evaluable> >));

int main()
{
    return 0;
}
