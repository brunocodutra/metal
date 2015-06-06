// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/bind.hpp>
#include <boost/mpl2/metafunctional/placeholders.hpp>
#include <boost/mpl2/metafunctional/protect.hpp>
#include <boost/mpl2/metafunctional/function.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>

#include "test.hpp"

using namespace boost::mpl2;
using namespace boost::mpl2::placeholders;

BOOST_MPL2_ASSERT((std::is_same<call<bind<test::wrapper>, void, void*>::type, test::wrap<> >));

BOOST_MPL2_ASSERT((std::is_same<call<bind<test::wrapper, _1>, short, int, long, long long>::type, test::wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<test::wrapper, _1, _2>, short, int, long, long long>::type, test::wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<test::wrapper, _1, _2, _3>, short, int, long, long long>::type, test::wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<test::wrapper, _1, _2, _3, _4>, short, int, long, long long>::type, test::wrap<short, int, long, long long> >));

using compose = protect<bind<_1, bind<_2, _3> > >;
BOOST_MPL2_ASSERT((is_evaluable<compose>));
BOOST_MPL2_ASSERT((is_function<compose>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, function<std::add_pointer>, function<std::add_const>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, function<std::add_const>, function<std::add_pointer>, void>::type, void* const>));

using once = protect<bind<compose, protect<_1>, _1, _2> >;
BOOST_MPL2_ASSERT((is_evaluable<once>));
BOOST_MPL2_ASSERT((is_function<once>));
BOOST_MPL2_ASSERT((std::is_same<call<once, function<std::add_pointer>, void>::type, void*>));

using twice = protect<bind<compose, _1, _1, _2> >;
BOOST_MPL2_ASSERT((is_evaluable<twice>));
BOOST_MPL2_ASSERT((is_function<twice>));
BOOST_MPL2_ASSERT((std::is_same<call<twice, function<std::add_pointer>, void>::type, void**>));

using thrice = protect<bind<once, _1, bind<twice, _1, _2> > >;
BOOST_MPL2_ASSERT((is_evaluable<thrice>));
BOOST_MPL2_ASSERT((is_function<thrice>));
BOOST_MPL2_ASSERT((std::is_same<call<thrice, function<std::add_pointer>, void>::type, void***>));

using ptr2ptr2ptr = protect<bind<thrice, function<std::add_pointer>, _1> >;
BOOST_MPL2_ASSERT((is_evaluable<ptr2ptr2ptr>));
BOOST_MPL2_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_MPL2_ASSERT((std::is_same<call<ptr2ptr2ptr, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, void> >::type, void***>));

int main()
{
    return 0;
}
