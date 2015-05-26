// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/apply.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

struct incomplete;
struct empty {};

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

using p0 = detail::args<detail::args<>, detail::args<detail::args<>, detail::args<>, detail::args<> > >;
using p1 = detail::args<p0, short, p0>;
using p2 = detail::args<int, p1>;
using p3 = detail::args<detail::args<long>, detail::args<detail::args<p2> > >;
using p4 = detail::args<p0, p0, p0, long long, detail::args<detail::args<p3> > >;

BOOST_MPL2_ASSERT((std::is_same<apply<void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<apply<void()>::type, void()>));
BOOST_MPL2_ASSERT((std::is_same<apply<incomplete>::type, incomplete>));
BOOST_MPL2_ASSERT((std::is_same<apply<empty>::type, empty>));

BOOST_MPL2_ASSERT((std::is_same<apply<_1, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<apply<std::add_pointer<_1>, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<apply<protect<lambda<std::add_pointer<_1> > >, void>::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, void>::type, wrap<void> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, short, int, long, long long>::type, wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_0>, void, void*>::type, wrap<void, void*> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_0, _0>, void, void*>::type, wrap<void, void*, void, void*> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_0, _0, _0>, void, void*>::type, wrap<void, void*, void, void*, void, void*> >));

BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_1>, short, int, long, long long>::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_1, _2>, short, int, long, long long>::type, wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_1, _2, _3>, short, int, long, long long>::type, wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_1, _2, _3, _4>, short, int, long, long long>::type, wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_>, short, int, long, long long>::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_, _>, short, int, long, long long>::type, wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_, _, _>, short, int, long, long long>::type, wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_, _, _, _>, short, int, long, long long>::type, wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<apply<lambda<_1>, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<apply<lambda<lambda<_1> >, void>::type, void>));

BOOST_MPL2_ASSERT((std::is_same<apply<lambda<_1>, protect<_1> >::type, protect<_1> >));
BOOST_MPL2_ASSERT((std::is_same<apply<protect<_1>, lambda<_1> >::type, lambda<_1> >));

BOOST_MPL2_ASSERT((std::is_same<apply<quote<protect>, _1>::type, protect<_1> >));

BOOST_MPL2_ASSERT((std::is_same<apply<apply<std::add_pointer<_1>, void>, void*>::type, void**>));
BOOST_MPL2_ASSERT((std::is_same<apply<call<_1, void>, lambda<std::add_pointer<_1> > >::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<apply<apply<lambda<std::add_pointer<_1> >, void> >::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<apply<apply<_1, void>, std::add_pointer<_1> >::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, p0>::type, wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, p1>::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, p2>::type, wrap<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, p3>::type, wrap<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, p4>::type, wrap<long long, long, int, short> >));

BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, long long, long, int, short, p0, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, long long, long, int, p1, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, long long, long, p2, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, long long, p3, char>::type, wrap<long long, long, int, short, char> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, p4, char>::type, wrap<long long, long, int, short, char> >));

BOOST_MPL2_ASSERT((std::is_same<apply<detail::args<wrapper, p0> >::type, wrap<> >));
BOOST_MPL2_ASSERT((std::is_same<apply<detail::args<wrapper, p1> >::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<detail::args<wrapper, p2> >::type, wrap<int, short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<detail::args<wrapper, p3> >::type, wrap<long, int, short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<detail::args<wrapper, p4> >::type, wrap<long long, long, int, short> >));

using compose = apply<_1, apply<_2, _3> >;
BOOST_MPL2_ASSERT((std::is_same<apply<compose, std::add_pointer<_1>, std::add_const<_1>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<apply<compose, std::add_const<_1>, std::add_pointer<_1>, void>::type, void* const>));

using once = apply<lambda<compose>, lambda<_>, _, _>;
BOOST_MPL2_ASSERT((std::is_same<apply<once, std::add_pointer<_1>, void>::type, void*>));

using twice = apply<lambda<compose>, _, _1, _>;
BOOST_MPL2_ASSERT((std::is_same<apply<twice, std::add_pointer<_1>, void>::type, void**>));

using thrice = apply<lambda<once>, _, apply<lambda<twice>, _, _> >;
BOOST_MPL2_ASSERT((std::is_same<apply<thrice, std::add_pointer<_1>, void>::type, void***>));

using ptr2ptr2ptr = apply<lambda<thrice>, lambda<std::add_pointer<_1> >, _1>;
BOOST_MPL2_ASSERT((std::is_same<apply<ptr2ptr2ptr, void>::type, void***>));

int main()
{
    return 0;
}
