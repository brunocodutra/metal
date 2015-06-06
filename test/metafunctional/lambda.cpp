// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/lambda.hpp>
#include <boost/mpl2/metafunctional/placeholders.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/protect.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>

#include "test.hpp"

using namespace boost::mpl2;
using namespace boost::mpl2::placeholders;

BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::fundamental> >::type, test::fundamental>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::function> >::type, test::function>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::incomplete> >::type, test::incomplete>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::empty> >::type, test::empty>));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<_1>, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<std::add_pointer<_1> >, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<protect<lambda<std::add_pointer<_1> > > >, void>::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::wrapper>, short, int, long, long long>::type, test::wrapper>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<protect<test::wrapper> >, void>::type, test::wrap<void> >));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::wrap<_1> >, short, int, long, long long>::type, test::wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::wrap<_1, _2> >, short, int, long, long long>::type, test::wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::wrap<_1, _2, _3> >, short, int, long, long long>::type, test::wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<test::wrap<_1, _2, _3, _4> >, short, int, long, long long>::type, test::wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<lambda<_1> >, void>::type, lambda<void> >));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<protect<lambda<_1> > >, void>::type, void>));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<lambda<_1> >, protect<_1> >::type, lambda<protect<_1> > >));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<protect<_1> >, lambda<_1> >::type, lambda<_1> >));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<quoter<protect> >, _1>::type, quoter<protect> >));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<protect<quoter<protect> > >, _1>::type, protect<_1> >));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<call<lambda<std::add_pointer<_1> >, void> >, void*>::type, void**>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<call<_1, void> >, lambda<std::add_pointer<_1> > >::type, void*>));

using compose = protect<lambda<call<lambda<_1>, call<lambda<_2>, _3> > > >;
BOOST_MPL2_ASSERT((is_function<compose>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, std::add_pointer<_1>, std::add_const<_1>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, std::add_const<_1>, std::add_pointer<_1>, void>::type, void* const>));

using once = protect<lambda<call<compose, protect<_1>, _1, _2> > >;
BOOST_MPL2_ASSERT((is_function<once>));
BOOST_MPL2_ASSERT((std::is_same<call<once, std::add_pointer<_1>, void>::type, void*>));

using twice = protect<lambda<call<compose, _1, _1, _2> > >;
BOOST_MPL2_ASSERT((is_function<twice>));
BOOST_MPL2_ASSERT((std::is_same<call<twice, std::add_pointer<_1>, void>::type, void**>));

using thrice = protect<lambda<call<once, _1, call<twice, _1, _2> > > >;
BOOST_MPL2_ASSERT((is_function<thrice>));
BOOST_MPL2_ASSERT((std::is_same<call<thrice, std::add_pointer<_1>, void>::type, void***>));

using ptr2ptr2ptr = protect<lambda<call<thrice, protect<lambda<std::add_pointer<_1> > >, _1> > >;
BOOST_MPL2_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_MPL2_ASSERT((std::is_same<call<ptr2ptr2ptr, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<ptr2ptr2ptr>, void>::type, void***>));

int main()
{
    return 0;
}
