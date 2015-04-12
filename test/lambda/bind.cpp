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

using compose = protect<bind<arg<1>, bind<arg<2>, arg<3> > > >;
BOOST_MPL2_ASSERT((std::is_same<eval<compose, function<std::add_pointer>, function<std::add_const>, void>, void const*>));
BOOST_MPL2_ASSERT((std::is_same<eval<compose, function<std::add_const>, function<std::add_pointer>, void>, void* const>));

using once = protect<bind<compose, protect<arg<1> >, arg<1>, arg<2> > >;
BOOST_MPL2_ASSERT((std::is_same<eval<once, function<std::add_pointer>, void>, void*>));

using twice = protect<bind<compose, arg<1>, arg<1>, arg<2> > >;
BOOST_MPL2_ASSERT((std::is_same<eval<twice, function<std::add_pointer>, void>, void**>));

using thrice = protect<bind<once, arg<1>, bind<twice, arg<1>, arg<2> > > >;
BOOST_MPL2_ASSERT((std::is_same<eval<thrice, function<std::add_pointer>, void>, void***>));

int main()
{
    return 0;
}
