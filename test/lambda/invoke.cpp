// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/invoke.hpp>
#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

template<typename...>
struct wrap;

struct wrapper
{
    template<typename... args>
    struct call
    {
        using type = wrap<args...>;
    };
};

BOOST_MPL2_ASSERT((is_invocable<wrapper, void>));
BOOST_MPL2_ASSERT((std::is_same<invoke<wrapper, void>::type, wrap<void> >));

BOOST_MPL2_ASSERT((is_invocable<wrapper, short, int, long, long long>));
BOOST_MPL2_ASSERT((std::is_same<invoke<wrapper, short, int, long, long long>::type, wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((is_invocable<wrapper, pack<short, int, long, long long> >));
BOOST_MPL2_ASSERT((std::is_same<invoke<wrapper, pack<short, int, long, long long> >::type, wrap<short, int, long, long long> >));

BOOST_MPL2_ASSERT((is_invocable<pack<wrapper, short, int, long, long long> >));
BOOST_MPL2_ASSERT((std::is_same<invoke<pack<wrapper, short, int, long, long long> >::type, wrap<short, int, long, long long> >));

int main()
{
    return 0;
}

