// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/apply.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/pack.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

struct incomplete;
struct empty {};
struct voider {using type = void;};

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

BOOST_MPL2_ASSERT((std::is_same<apply<void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<apply<void()>::type, void()>));
BOOST_MPL2_ASSERT((std::is_same<apply<incomplete>::type, incomplete>));
BOOST_MPL2_ASSERT((std::is_same<apply<empty>::type, empty>));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_>, void>::type, wrap<void> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_>, short, int, long, long long>::type, wrap<short, int, long, long long> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrap<_>, pack<short, int, long, long long> >::type, wrap<short, int, long, long long> >));
BOOST_MPL2_ASSERT((std::is_same<apply<pack<wrap<_>, short, int, long, long long> >::type, wrap<short, int, long, long long> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, void>::type, wrap<void> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, short, int, long, long long>::type, wrap<short, int, long, long long> >));
BOOST_MPL2_ASSERT((std::is_same<apply<wrapper, pack<short, int, long, long long> >::type, wrap<short, int, long, long long> >));
BOOST_MPL2_ASSERT((std::is_same<apply<pack<wrapper, short, int, long, long long> >::type, wrap<short, int, long, long long> >));

using compose = apply<_1, apply<_2, _3> >;
BOOST_MPL2_ASSERT((std::is_same<apply<compose, std::add_pointer<_1>, std::add_const<_1>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<apply<compose, std::add_const<_1>, std::add_pointer<_1>, void>::type, void* const>));

using once = apply<lambda<compose>, lambda<_1>, _1, _2>;
BOOST_MPL2_ASSERT((std::is_same<apply<once, std::add_pointer<_1>, void>::type, void*>));

using twice = apply<lambda<compose>, _1, _1, _2>;
BOOST_MPL2_ASSERT((std::is_same<apply<twice, std::add_pointer<_1>, void>::type, void**>));

using thrice = apply<lambda<once>, _1, apply<lambda<twice>, _1, _2> >;
BOOST_MPL2_ASSERT((std::is_same<apply<thrice, std::add_pointer<_1>, void>::type, void***>));

using ptr2ptr2ptr = apply<lambda<thrice>, lambda<std::add_pointer<_1> >, _1>;
BOOST_MPL2_ASSERT((std::is_same<apply<ptr2ptr2ptr, void>::type, void***>));

int main()
{
    return 0;
}
