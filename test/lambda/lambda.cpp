// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/lambda.hpp>
#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using compose = protect<lambda<call<lambda<_1>, call<lambda<_2>, _3> > > >;
BOOST_MPL2_ASSERT((std::is_same<call<compose, std::add_pointer<_1>, std::add_const<_1>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, std::add_const<_1>, std::add_pointer<_1>, void>::type, void* const>));

using once = protect<lambda<call<compose, protect<_1>, _1, _2> > >;
BOOST_MPL2_ASSERT((std::is_same<call<once, std::add_pointer<_1>, void>::type, void*>));

using twice = protect<lambda<call<compose, _1, _1, _2> > >;
BOOST_MPL2_ASSERT((std::is_same<call<twice, std::add_pointer<_1>, void>::type, void**>));

using thrice = protect<lambda<call<once, _1, call<twice, _1, _2> > > >;
BOOST_MPL2_ASSERT((std::is_same<call<thrice, std::add_pointer<_1>, void>::type, void***>));

using ptr2ptr2ptr = protect<lambda<call<thrice, protect<lambda<std::add_pointer<_1> > >, _1> > >;
BOOST_MPL2_ASSERT((std::is_same<call<ptr2ptr2ptr, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, void> >::type, void***>));

int main()
{
    return 0;
}
