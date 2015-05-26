// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;


template<typename... args>
struct wrap
{
    using type = wrap<args...>;
};

struct wrapper
{
    template<typename... args>
    using call = wrap<args...>;
};

struct f0
{
    template<typename x=void>
    struct call :
            wrap<>
    {};
};

struct f1
{
    template<typename x>
    using call = wrap<x>;
};

struct f2
{
    template<typename x, typename y>
    using call = wrap<x, y>;
};

using fn = wrapper;

BOOST_MPL2_ASSERT((std::is_same<call<f0>::type, f0::call<>::type>));
BOOST_MPL2_ASSERT((std::is_same<call<f1, void>::type, f1::call<void>::type>));
BOOST_MPL2_ASSERT((std::is_same<call<f2, void, void*>::type, f2::call<void, void*>::type>));

BOOST_MPL2_ASSERT((std::is_same<call<fn>::type, fn::call<> >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short>::type, fn::call<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int>::type, fn::call<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int, long>::type, fn::call<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<call<fn, short, int, long, long long>::type, fn::call<short, int, long, long long> >));

using p0 = detail::args<detail::args<>, detail::args<detail::args<>, detail::args<>, detail::args<> > >;
using p1 = detail::args<p0, short, p0>;
using p2 = detail::args<int, p1>;
using p3 = detail::args<detail::args<long>, detail::args<detail::args<p2> > >;
using p4 = detail::args<p0, p0, p0, long long, detail::args<detail::args<p3> > >;

BOOST_MPL2_ASSERT((std::is_same<call<wrapper, p0>::type, wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, p1>::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, p2>::type, wrap<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, p3>::type, wrap<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, p4>::type, wrap<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<call<wrapper, long long, long, int, short, p0, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, long long, long, int, p1, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, long long, long, p2, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, long long, p3, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, p4, char>::type, wrap<long long, long, int, short, char> >));

BOOST_MPL2_ASSERT((std::is_same<call<detail::args<wrapper, p0> >::type, wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<call<detail::args<wrapper, p1> >::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<detail::args<wrapper, p2> >::type, wrap<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<call<detail::args<wrapper, p3> >::type, wrap<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<call<detail::args<wrapper, p4> >::type, wrap<long long, long, int, short> >));

int main()
{
    return 0;
}

