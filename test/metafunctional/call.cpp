// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

template<typename...> struct result;

struct f1
{
    template<typename x>
    using call = identity<result<x> >;
};

struct f2
{
    template<typename x, typename y>
    using call = identity<result<x, y> >;
};

struct fn
{
    template<typename... args>
    using call = identity<result<args...> >;
};

BOOST_MPL2_ASSERT((std::is_same<call<f1, void>::type, f1::call<void>::type >));
BOOST_MPL2_ASSERT((std::is_same<call<f2, void, void*>::type, f2::call<void, void*>::type >));

BOOST_MPL2_ASSERT((std::is_same<call<fn>::type, fn::call<>::type >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short>::type, fn::call<short>::type >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int>::type, fn::call<short, int>::type >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int, long>::type, fn::call<short, int, long>::type >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int, long, long long>::type, fn::call<short, int, long, long long>::type >));

int main()
{
    return 0;
}

