// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/traits.hpp>
#include <boost/mpl2/lambda/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

struct incomplete;
struct empty {};

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

BOOST_MPL2_ASSERT((not_<is_callable<void> >));
BOOST_MPL2_ASSERT((not_<is_callable<void()> >));
BOOST_MPL2_ASSERT((not_<is_callable<incomplete> >));
BOOST_MPL2_ASSERT((not_<is_callable<empty> >));

BOOST_MPL2_ASSERT((is_callable<wrapper, void>));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, void>::type, wrap<void> >));

BOOST_MPL2_ASSERT((is_callable<wrapper, short, int, long, long long>));
BOOST_MPL2_ASSERT((std::is_same<call<wrapper, short, int, long, long long>::type, wrap<short, int, long, long long> >));

int main()
{
    return 0;
}

