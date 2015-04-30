// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/lambda.hpp>
#include <boost/mpl2/lambda/arg.hpp>
#include <boost/mpl2/lambda/apply.hpp>
#include <boost/mpl2/lambda/invoke.hpp>
#include <boost/mpl2/lambda/protect.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<void> >::type, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<_1>, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<std::add_pointer<_1> >, void>::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<invoke<protect<lambda<std::add_pointer<_1> > >, void>::type, void*>));

struct voider
{
    template<typename...>
    struct call
    {
        using type = void;
    };
};

BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<voider> >::type, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<voider>, short>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<voider>, short, int>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<voider>, short, int, long>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<voider>, short, int, long>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<voider>, short, int, long, long>::type, void>));

BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<lambda<_1> >, void>::type, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<lambda<lambda<_1> > >, void>::type, void>));

BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<lambda<_1> >, protect<_1> >::type, protect<_1> >));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<protect<_1> >, lambda<_1> >::type, lambda<_1> >));

BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<quoter<protect> >, _1>::type, protect<_1> >));

BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<invoke<lambda<std::add_pointer<_1> >, void> > >::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<invoke<_1, void> >, lambda<std::add_pointer<_1> > >::type, void*>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<apply<_1, void> >, std::add_pointer<_1> >::type, void*>));

using compose = lambda<apply<_1, apply<_2, _3> > >;
BOOST_MPL2_ASSERT((std::is_same<invoke<compose, std::add_pointer<_1>, std::add_const<_1>, void>::type, void const*>));
BOOST_MPL2_ASSERT((std::is_same<invoke<compose, std::add_const<_1>, std::add_pointer<_1>, void>::type, void* const>));

using once = lambda<invoke<compose, lambda<_1>, _1, _2> >;
BOOST_MPL2_ASSERT((std::is_same<invoke<once, std::add_pointer<_1>, void>::type, void*>));

using twice = lambda<invoke<compose, _1, _1, _2> >;
BOOST_MPL2_ASSERT((std::is_same<invoke<twice, std::add_pointer<_1>, void>::type, void**>));

using thrice = lambda<invoke<once, _1, invoke<twice, _1, _2> > >;
BOOST_MPL2_ASSERT((std::is_same<invoke<thrice, std::add_pointer<_1>, void>::type, void***>));

using ptr2ptr2ptr = lambda<invoke<thrice, lambda<std::add_pointer<_1> > , _1> >;
BOOST_MPL2_ASSERT((std::is_same<invoke<ptr2ptr2ptr, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<ptr2ptr2ptr>, void>::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<invoke<bind<ptr2ptr2ptr, void> >::type, void***>));
BOOST_MPL2_ASSERT((std::is_same<invoke<lambda<bind<ptr2ptr2ptr, void> > >::type, void***>));

int main()
{
    return 0;
}
