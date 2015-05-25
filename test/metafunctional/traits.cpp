// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/traits.hpp>
#include <boost/mpl2/core/logical/not.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using fundamental = void;
using func = void();
struct incomplete;
struct empty {};

template<typename...>
struct call {};
struct eponym : ::call<> {};

struct evaluable {struct type{};};

struct oneary_fundamental {template<typename> using call = fundamental;};
struct oneary_func {template<typename> using call = func;};
struct oneary_incomplete {template<typename> using call = incomplete;};
struct oneary_empty {template<typename> using call = empty;};
struct oneary_eponym {template<typename> using call = eponym;};
struct oneary_evaluable {template<typename> using call = evaluable;};

struct nullary_fundamental {template<typename=void> using call = fundamental;};
struct nullary_func {template<typename=void> using call = func;};
struct nullary_incomplete {template<typename=void> using call = incomplete;};
struct nullary_empty {template<typename=void> using call = empty;};
struct nullary_eponym {template<typename=void> using call = eponym;};
struct nullary_evaluable {template<typename=void> using call = evaluable;};

BOOST_MPL2_ASSERT((not_<is_evaluable<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<func> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<empty> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<eponym> >));
BOOST_MPL2_ASSERT((is_evaluable<evaluable>));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_fundamental> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_func> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_incomplete> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_empty> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_eponym> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_evaluable> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_fundamental> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_func> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_incomplete> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_empty> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_eponym> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_evaluable> >));

BOOST_MPL2_ASSERT((not_<is_function<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_function<func> >));
BOOST_MPL2_ASSERT((not_<is_function<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_function<empty> >));
BOOST_MPL2_ASSERT((not_<is_function<eponym> >));
BOOST_MPL2_ASSERT((not_<is_function<evaluable> >));
BOOST_MPL2_ASSERT((is_function<oneary_fundamental>));
BOOST_MPL2_ASSERT((is_function<oneary_func>));
BOOST_MPL2_ASSERT((is_function<oneary_incomplete>));
BOOST_MPL2_ASSERT((is_function<oneary_empty>));
BOOST_MPL2_ASSERT((is_function<oneary_eponym>));
BOOST_MPL2_ASSERT((is_function<oneary_evaluable>));
BOOST_MPL2_ASSERT((is_function<nullary_fundamental>));
BOOST_MPL2_ASSERT((is_function<nullary_func>));
BOOST_MPL2_ASSERT((is_function<nullary_incomplete>));
BOOST_MPL2_ASSERT((is_function<nullary_empty>));
BOOST_MPL2_ASSERT((is_function<nullary_eponym>));
BOOST_MPL2_ASSERT((is_function<nullary_evaluable>));

BOOST_MPL2_ASSERT((not_<is_callable<> >));
BOOST_MPL2_ASSERT((not_<is_callable<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_callable<func> >));
BOOST_MPL2_ASSERT((not_<is_callable<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_callable<empty> >));
BOOST_MPL2_ASSERT((not_<is_callable<eponym> >));
BOOST_MPL2_ASSERT((not_<is_callable<evaluable> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_fundamental> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_func> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_incomplete> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_empty> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_eponym> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_evaluable> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_fundamental> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_func> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_incomplete> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_empty> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_eponym> >));
BOOST_MPL2_ASSERT((is_callable<nullary_evaluable>));

BOOST_MPL2_ASSERT((not_<is_applicable<> >));
BOOST_MPL2_ASSERT((is_applicable<fundamental>));
BOOST_MPL2_ASSERT((is_applicable<func>));
BOOST_MPL2_ASSERT((is_applicable<incomplete>));
BOOST_MPL2_ASSERT((is_applicable<empty>));
BOOST_MPL2_ASSERT((is_applicable<eponym>));
BOOST_MPL2_ASSERT((is_applicable<evaluable>));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary_fundamental> >));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary_func> >));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary_incomplete> >));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary_empty> >));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary_eponym> >));
BOOST_MPL2_ASSERT((not_<is_applicable<oneary_evaluable> >));
BOOST_MPL2_ASSERT((not_<is_applicable<nullary_fundamental> >));
BOOST_MPL2_ASSERT((not_<is_applicable<nullary_func> >));
BOOST_MPL2_ASSERT((not_<is_applicable<nullary_incomplete> >));
BOOST_MPL2_ASSERT((not_<is_applicable<nullary_empty> >));
BOOST_MPL2_ASSERT((not_<is_applicable<nullary_eponym> >));
BOOST_MPL2_ASSERT((is_applicable<nullary_evaluable>));

int main()
{
    return 0;
}
