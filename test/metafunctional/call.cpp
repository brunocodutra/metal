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
    using call = test::wrap<x>;
};

struct f2
{
    template<typename x, typename y>
    using call = test::wrap<x, y>;
};

using fn = test::wrapper;

BOOST_MPL2_ASSERT((std::is_same<call<f0>::type, f0::call<>::type>));
BOOST_MPL2_ASSERT((std::is_same<call<f1, void>::type, f1::call<void>::type>));
BOOST_MPL2_ASSERT((std::is_same<call<f2, void, void*>::type, f2::call<void, void*>::type>));

BOOST_MPL2_ASSERT((std::is_same<call<fn>::type, fn::call<> >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short>::type, fn::call<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int>::type, fn::call<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int, long>::type, fn::call<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int, long, long long>::type, fn::call<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, test::args0>::type, test::wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, test::args1>::type, test::wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, test::args2>::type, test::wrap<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, test::args3>::type, test::wrap<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, test::args4>::type, test::wrap<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, long long, long, int, short, test::args0, char>::type, test::wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, long long, long, int, test::args1, char>::type, test::wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, long long, long, test::args2, char>::type, test::wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, long long, test::args3, char>::type, test::wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<call<test::wrapper, test::args4, char>::type, test::wrap<long long, long, int, short, char> >));

BOOST_MPL2_ASSERT((std::is_same<call<detail::args<test::wrapper, test::args0> >::type, test::wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<call<detail::args<test::wrapper, test::args1> >::type, test::wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<detail::args<test::wrapper, test::args2> >::type, test::wrap<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<call<detail::args<test::wrapper, test::args3> >::type, test::wrap<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<call<detail::args<test::wrapper, test::args4> >::type, test::wrap<long long, long, int, short> >));

int main()
{
    return 0;
}

