// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/call.hpp>

#include "test.hpp"

using namespace boost::mpl2;

struct f0
{
    template<typename = void>
    struct call :
            test::wrap<>
    {};
};

struct f1
{
    template<typename x>
    struct call :
            test::wrap<x>
    {};
};

struct f2
{
    template<typename x, typename y>
    struct call :
            test::wrap<x, y>
    {};
};

using fn = test::wrapper;

BOOST_MPL2_ASSERT((std::is_same<call_t<f0>, f0::call<>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<f1, void>, f1::call<void>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<f2, void, void*>, f2::call<void, void*>::type>));

BOOST_MPL2_ASSERT((std::is_same<call_t<fn>, fn::call<>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<fn, short>, fn::call<short>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<fn, short, int>, fn::call<short, int>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<fn, short, int, long>, fn::call<short, int, long>::type>));
BOOST_MPL2_ASSERT((std::is_same<call_t<fn, short, int, long, long long>, fn::call<short, int, long, long long>::type>));

int main()
{
    return 0;
}

