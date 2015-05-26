// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/bind.hpp>
#include <boost/mpl2/metafunctional/protect.hpp>
#include <boost/mpl2/metafunctional/function.hpp>
#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

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

BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper>, void>::type, wrap<> >));

BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _0>, void, void*>::type, wrap<void, void*> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _0, _0>, void, void*>::type, wrap<void, void*, void, void*> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _0, _0, _0>, void, void*>::type, wrap<void, void*, void, void*, void, void*> >));

BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _1>, short, int, long, long long>::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _1, _2>, short, int, long, long long>::type, wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _1, _2, _3>, short, int, long, long long>::type, wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _1, _2, _3, _4>, short, int, long, long long>::type, wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _>, short, int, long, long long>::type, wrap<short> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _, _>, short, int, long, long long>::type, wrap<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _, _, _>, short, int, long, long long>::type, wrap<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<call<bind<wrapper, _, _, _, _>, short, int, long, long long>::type, wrap<short, int, long, long long> >));

using compose = protect<bind<_1, bind<_2, _3> > >;
BOOST_MPL2_ASSERT((is_evaluable<compose>));
BOOST_MPL2_ASSERT((is_function<compose>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, function<std::add_pointer>, function<std::add_const>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<call<compose, function<std::add_const>, function<std::add_pointer>, void>::type, void* const>));

using once = protect<bind<compose, protect<_1>, _, _> >;
BOOST_MPL2_ASSERT((is_evaluable<once>));
BOOST_MPL2_ASSERT((is_function<once>));
BOOST_MPL2_ASSERT((std::is_same<call<once, function<std::add_pointer>, void>::type, void*>));

using twice = protect<bind<compose, _, _1, _> >;
BOOST_MPL2_ASSERT((is_evaluable<twice>));
BOOST_MPL2_ASSERT((is_function<twice>));
BOOST_MPL2_ASSERT((std::is_same<call<twice, function<std::add_pointer>, void>::type, void**>));

using thrice = protect<bind<once, _, bind<twice, _, _> > >;
BOOST_MPL2_ASSERT((is_evaluable<thrice>));
BOOST_MPL2_ASSERT((is_function<thrice>));
BOOST_MPL2_ASSERT((std::is_same<call<thrice, function<std::add_pointer>, void>::type, void***>));

using ptr2ptr2ptr = protect<bind<thrice, function<std::add_pointer>, _1> >;
BOOST_MPL2_ASSERT((is_evaluable<ptr2ptr2ptr>));
BOOST_MPL2_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_MPL2_ASSERT((std::is_same<call<ptr2ptr2ptr, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, void> >::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, _0>, void >::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, _0, _0>, void >::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, _0, _0, _0>, void >::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<call<bind<ptr2ptr2ptr, _0, _0, _0, _0>, void >::type, void***>));

int main()
{
    return 0;
}
