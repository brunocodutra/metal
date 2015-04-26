// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/lambda.hpp>
#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/apply.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/protect.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((std::is_same<call<lambda<void> >::type, void>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<_1>, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<std::add_pointer<_1> >, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<protect<lambda<std::add_pointer<_1> > >, void>::type, void*>));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<lambda<_1> >, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<lambda<lambda<_1> > >, void>::type, void>));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<lambda<_1> >, protect<_1> >::type, protect<_1> >));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<protect<_1> >, lambda<_1> >::type, lambda<_1> >));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<quote<protect> >, _1>::type, protect<_1> >));

BOOST_MPL2_ASSERT((std::is_same<call<lambda<call<lambda<std::add_pointer<_1> >, void> > >::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<call<_1, void> >, lambda<std::add_pointer<_1> > >::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<apply<_1, void> >, std::add_pointer<_1> >::type, void*>));

using compose = lambda<apply<_1, apply<_2, _3> > >;
BOOST_MPL2_ASSERT((std::is_same<call<compose, std::add_pointer<_1>, std::add_const<_1>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, std::add_const<_1>, std::add_pointer<_1>, void>::type, void* const>));

using once = lambda<call<compose, lambda<_1>, _1, _2> >;
BOOST_MPL2_ASSERT((std::is_same<call<once, std::add_pointer<_1>, void>::type, void*>));

using twice = lambda<call<compose, _1, _1, _2> >;
BOOST_MPL2_ASSERT((std::is_same<call<twice, std::add_pointer<_1>, void>::type, void**>));

using thrice = lambda<call<once, _1, call<twice, _1, _2> > >;
BOOST_MPL2_ASSERT((std::is_same<call<thrice, std::add_pointer<_1>, void>::type, void***>));

using ptr2ptr2ptr = lambda<call<thrice, lambda<std::add_pointer<_1> > , _1> >;
BOOST_MPL2_ASSERT((std::is_same<call<ptr2ptr2ptr, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<ptr2ptr2ptr>, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, void> >::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<lambda<bind<ptr2ptr2ptr, void> > >::type, void***>));

int main()
{
    return 0;
}
