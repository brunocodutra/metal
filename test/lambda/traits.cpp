// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using fundamental = void;

struct incomplete;
struct empty {};
struct evaluable {struct type;};

struct oneary_incomplete_call {template<typename> struct call;};
struct oneary_empty_call {template<typename> struct call{};};
struct oneary_evaluable_call {template<typename> struct call{using type = void;};};

struct nullary_incomplete_call {template<typename=void> struct call;};
struct nullary_empty_call {template<typename=void> struct call{};};
struct nullary_evaluable_call {template<typename=void> struct call{enum type{};};};

BOOST_MPL2_ASSERT((not_<is_evaluable<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<empty> >));
BOOST_MPL2_ASSERT((is_evaluable<evaluable>));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_incomplete_call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_empty_call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<oneary_evaluable_call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_incomplete_call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_empty_call> >));
BOOST_MPL2_ASSERT((not_<is_evaluable<nullary_evaluable_call> >));

BOOST_MPL2_ASSERT((not_<is_function<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_function<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_function<empty> >));
BOOST_MPL2_ASSERT((not_<is_function<evaluable> >));
BOOST_MPL2_ASSERT((is_function<oneary_incomplete_call>));
BOOST_MPL2_ASSERT((is_function<oneary_empty_call>));
BOOST_MPL2_ASSERT((is_function<oneary_evaluable_call>));
BOOST_MPL2_ASSERT((is_function<nullary_incomplete_call>));
BOOST_MPL2_ASSERT((is_function<nullary_empty_call>));
BOOST_MPL2_ASSERT((is_function<nullary_evaluable_call>));

BOOST_MPL2_ASSERT((not_<is_callable<fundamental> >));
BOOST_MPL2_ASSERT((not_<is_callable<empty> >));
BOOST_MPL2_ASSERT((not_<is_callable<evaluable> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_incomplete_call> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_empty_call> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_evaluable_call> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_incomplete_call> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_empty_call> >));
BOOST_MPL2_ASSERT((is_callable<nullary_evaluable_call>));

int main()
{
    return 0;
}
