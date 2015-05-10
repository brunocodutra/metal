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

struct oneary_incomplete_function {template<typename> struct call;};
struct oneary_empty_function {template<typename> struct call{};};
struct oneary_evaluable_function {template<typename> struct call{struct type{};};};

struct nullary_incomplete_function {template<typename=void> struct call;};
struct nullary_empty_function {template<typename=void> struct call{};};
struct nullary_evaluable_function {template<typename=void> struct call{enum type{};};};

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((not_<is_function<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_function<func> >));
BOOST_MPL2_ASSERT((not_<is_function<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_function<empty> >));
BOOST_MPL2_ASSERT((not_<is_function<eponym> >));
BOOST_MPL2_ASSERT((is_function<oneary_incomplete_function>));
BOOST_MPL2_ASSERT((is_function<oneary_empty_function>));
BOOST_MPL2_ASSERT((is_function<oneary_evaluable_function>));
BOOST_MPL2_ASSERT((is_function<nullary_incomplete_function>));
BOOST_MPL2_ASSERT((is_function<nullary_empty_function>));
BOOST_MPL2_ASSERT((is_function<nullary_evaluable_function>));

BOOST_MPL2_ASSERT((not_<is_callable<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_callable<func> >));
BOOST_MPL2_ASSERT((not_<is_callable<empty> >));
BOOST_MPL2_ASSERT((not_<is_callable<eponym> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_incomplete_function> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_empty_function> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_evaluable_function> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_incomplete_function> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_empty_function> >));
BOOST_MPL2_ASSERT((is_callable<nullary_evaluable_function>));

BOOST_MPL2_ASSERT((not_<is_invocable<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_invocable<func> >));
BOOST_MPL2_ASSERT((not_<is_invocable<empty> >));
BOOST_MPL2_ASSERT((not_<is_invocable<eponym> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_incomplete_function> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_empty_function> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_evaluable_function> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_incomplete_function> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_empty_function> >));
BOOST_MPL2_ASSERT((is_invocable<nullary_evaluable_function>));

int main()
{
    return 0;
}
