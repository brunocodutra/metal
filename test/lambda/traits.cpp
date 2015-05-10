// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/invoke.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using fundamental = void;
using func = void();
struct incomplete;
struct empty {};

template<typename...>
struct call {};
struct eponym : ::call<> {};

struct evaluable {struct type{};};

struct oneary_fundamental {template<typename> using call = fundamental();};
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

using namespace boost::mpl2;

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

BOOST_MPL2_ASSERT((not_<is_invocable<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_invocable<func> >));
BOOST_MPL2_ASSERT((not_<is_invocable<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_invocable<empty> >));
BOOST_MPL2_ASSERT((not_<is_invocable<eponym> >));
BOOST_MPL2_ASSERT((not_<is_invocable<evaluable> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_fundamental> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_func> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_incomplete> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_empty> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_eponym> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_evaluable> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_fundamental> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_func> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_incomplete> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_empty> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_eponym> >));
BOOST_MPL2_ASSERT((is_invocable<nullary_evaluable>));

int main()
{
    return 0;
}
