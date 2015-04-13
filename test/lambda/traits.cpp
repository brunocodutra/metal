// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using built_in_type = void;

struct undefined_struct;
struct empty_struct;
struct identity_struct {using type = identity_struct;};

struct oneary_undefined_call {template<typename> struct call;};
struct oneary_empty_call {template<typename> struct call{};};
struct oneary_call {template<typename> struct call{using type = void;};};

struct nullary_undefined_call {template<typename=void> struct call;};
struct nullary_empty_call {template<typename=void> struct call{};};
struct nullary_call {template<typename=void> struct call{using type = void;};};

BOOST_MPL2_ASSERT((not_<is_function<built_in_type> >));
BOOST_MPL2_ASSERT((not_<is_function<empty_struct> >));
BOOST_MPL2_ASSERT((not_<is_function<identity_struct> >));
BOOST_MPL2_ASSERT((is_function<oneary_undefined_call>));
BOOST_MPL2_ASSERT((is_function<oneary_empty_call>));
BOOST_MPL2_ASSERT((is_function<oneary_call>));
BOOST_MPL2_ASSERT((is_function<nullary_undefined_call>));
BOOST_MPL2_ASSERT((is_function<nullary_empty_call>));
BOOST_MPL2_ASSERT((is_function<nullary_call>));

BOOST_MPL2_ASSERT((not_<is_callable<built_in_type> >));
BOOST_MPL2_ASSERT((not_<is_callable<empty_struct> >));
BOOST_MPL2_ASSERT((not_<is_callable<identity_struct> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_undefined_call> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_empty_call> >));
BOOST_MPL2_ASSERT((not_<is_callable<oneary_call> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_undefined_call> >));
BOOST_MPL2_ASSERT((not_<is_callable<nullary_empty_call> >));
BOOST_MPL2_ASSERT((is_callable<nullary_call>));

int main()
{
    return 0;
}
