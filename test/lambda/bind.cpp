// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/bind.hpp>
#include <boost/mpl2/lambda/protect.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using compose = protect<bind<_1, bind<_2, _3> > >;
BOOST_MPL2_ASSERT((std::is_same<call<compose, function<std::add_pointer>, function<std::add_const>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, function<std::add_const>, function<std::add_pointer>, void>::type, void* const>));

using once = protect<bind<compose, protect<_1>, _1, _2> >;
BOOST_MPL2_ASSERT((std::is_same<call<once, function<std::add_pointer>, void>::type, void*>));

using twice = protect<bind<compose, _1, _1, _2> >;
BOOST_MPL2_ASSERT((std::is_same<call<twice, function<std::add_pointer>, void>::type, void**>));

using thrice = protect<bind<once, _1, bind<twice, _1, _2> > >;
BOOST_MPL2_ASSERT((std::is_same<call<thrice, function<std::add_pointer>, void>::type, void***>));

using ptr2ptr2ptr = protect<bind<thrice, function<std::add_pointer>, _1> >;
BOOST_MPL2_ASSERT((std::is_same<call<ptr2ptr2ptr, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, void> >::type, void***>));

int main()
{
    return 0;
}
