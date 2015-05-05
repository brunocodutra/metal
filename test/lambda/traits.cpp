// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/eval.hpp>
#include <boost/mpl2/lambda/invoke.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using fundamental = void;
using func = void();
struct incomplete;
struct empty {};

struct oneary_incomplete_call {template<typename> struct call;};
struct oneary_empty_call {template<typename> struct call{};};
struct oneary_evaluable_call {template<typename> struct call{using type = void;};};

struct nullary_incomplete_call {template<typename=void> struct call;};
struct nullary_empty_call {template<typename=void> struct call{};};
struct nullary_evaluable_call {template<typename=void> struct call{enum type{};};};

BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_incomplete_call::call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_empty_call::call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_evaluable_call::call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_incomplete_call::call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_empty_call::call> >));
BOOST_MPL2_ASSERT((is_evaluable<nullary_evaluable_call::call>));

BOOST_MPL2_ASSERT((not_<is_function<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_function<func> >));
BOOST_MPL2_ASSERT((not_<is_function<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_function<empty> >));
BOOST_MPL2_ASSERT((is_function<oneary_incomplete_call>));
BOOST_MPL2_ASSERT((is_function<oneary_empty_call>));
BOOST_MPL2_ASSERT((is_function<oneary_evaluable_call>));
BOOST_MPL2_ASSERT((is_function<nullary_incomplete_call>));
BOOST_MPL2_ASSERT((is_function<nullary_empty_call>));
BOOST_MPL2_ASSERT((is_function<nullary_evaluable_call>));

BOOST_MPL2_ASSERT((not_<is_invocable<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_invocable<func> >));
BOOST_MPL2_ASSERT((not_<is_invocable<empty> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_incomplete_call> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_empty_call> >));
BOOST_MPL2_ASSERT((not_<is_invocable<oneary_evaluable_call> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_incomplete_call> >));
BOOST_MPL2_ASSERT((not_<is_invocable<nullary_empty_call> >));
BOOST_MPL2_ASSERT((is_invocable<nullary_evaluable_call>));

int main()
{
    return 0;
}
