// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/apply.hpp>
#include <boost/mpl2/metafunctional/placeholders.hpp>

#include "test.hpp"

using namespace boost::mpl2;
using namespace boost::mpl2::placeholders;

BOOST_MPL2_ASSERT((std::is_same<apply<test::fundamental>::type, test::fundamental>));
BOOST_MPL2_ASSERT((std::is_same<apply<test::function>::type, test::function>));
BOOST_MPL2_ASSERT((std::is_same<apply<test::incomplete>::type, test::incomplete>));
BOOST_MPL2_ASSERT((std::is_same<apply<test::empty>::type, test::empty>));

BOOST_MPL2_ASSERT((std::is_same<apply<_1, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<apply<std::add_pointer<_1>, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<apply<protect<lambda<std::add_pointer<_1> > >, void>::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<apply<test::wrapper, void>::type, test::wrap<void> >));
BOOST_MPL2_ASSERT((std::is_same<apply<test::wrapper, short, int, long, long long>::type, test::wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<apply<test::wrap<_1>, short, int, long, long long>::type, test::wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<apply<test::wrap<_1, _2>, short, int, long, long long>::type, test::wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<apply<test::wrap<_1, _2, _3>, short, int, long, long long>::type, test::wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<apply<test::wrap<_1, _2, _3, _4>, short, int, long, long long>::type, test::wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<apply<lambda<_1>, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<apply<lambda<lambda<_1> >, void>::type, void>));

BOOST_MPL2_ASSERT((std::is_same<apply<lambda<_1>, protect<_1> >::type, protect<_1> >));
BOOST_MPL2_ASSERT((std::is_same<apply<protect<_1>, lambda<_1> >::type, lambda<_1> >));

BOOST_MPL2_ASSERT((std::is_same<apply<quote<protect>, _1>::type, protect<_1> >));

BOOST_MPL2_ASSERT((std::is_same<apply<apply<std::add_pointer<_1>, void>, void*>::type, void**>));
BOOST_MPL2_ASSERT((std::is_same<apply<call<_1, void>, lambda<std::add_pointer<_1> > >::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<apply<apply<lambda<std::add_pointer<_1> >, void> >::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<apply<apply<_1, void>, std::add_pointer<_1> >::type, void*>));

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
