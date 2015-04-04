// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/bind.hpp>
#include <boost/mpl2/core/quote.hpp>
#include <boost/mpl2/core/arg.hpp>
#include <boost/mpl2/core/apply.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using boost::mpl2::protect;
using boost::mpl2::bind;
using boost::mpl2::quote;
using boost::mpl2::arg;
using boost::mpl2::apply;

using compose = protect<bind<arg<1>, bind<arg<2>, arg<3> > > >;
BOOST_MPL2_ASSERT((std::is_same<apply<compose, quote<std::add_pointer>, quote<std::add_const>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<apply<compose, quote<std::add_const>, quote<std::add_pointer>, void>::type, void* const>));

using once = protect<bind<compose, protect<arg<1> >, arg<1>, arg<2> > >;
BOOST_MPL2_ASSERT((std::is_same<apply<once, quote<std::add_pointer>, void>::type, void*>));

using twice = protect<bind<compose, arg<1>, arg<1>, arg<2> > >;
BOOST_MPL2_ASSERT((std::is_same<apply<twice, quote<std::add_pointer>, void>::type, void**>));

using thrice = protect<bind<once, arg<1>, bind<twice, arg<1>, arg<2> > > >;
BOOST_MPL2_ASSERT((std::is_same<apply<thrice, quote<std::add_pointer>, void>::type, void***>));

int main()
{};
