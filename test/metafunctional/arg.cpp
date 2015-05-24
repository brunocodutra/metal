// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/arg.hpp>
#include <boost/mpl2/metafunctional/invoke.hpp>
#include <boost/mpl2/metafunctional/forward.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>
#include <boost/mpl2/core/logical/not.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

BOOST_MPL2_ASSERT(is_evaluable<_>);
BOOST_MPL2_ASSERT(is_evaluable<_1>);
BOOST_MPL2_ASSERT(is_evaluable<_2>);
BOOST_MPL2_ASSERT(is_evaluable<_3>);
BOOST_MPL2_ASSERT(is_evaluable<_4>);

BOOST_MPL2_ASSERT(is_function<_>);
BOOST_MPL2_ASSERT(is_function<_1>);
BOOST_MPL2_ASSERT(is_function<_2>);
BOOST_MPL2_ASSERT(is_function<_3>);
BOOST_MPL2_ASSERT(is_function<_4>);

BOOST_MPL2_ASSERT((is_invocable<_, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_invocable<_1, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_invocable<_2, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_invocable<_3, short, int, long, long long>));
BOOST_MPL2_ASSERT((is_invocable<_4, short, int, long, long long>));

BOOST_MPL2_ASSERT((is_invocable<_>));
BOOST_MPL2_ASSERT((not_<is_invocable<_1> >));
BOOST_MPL2_ASSERT((not_<is_invocable<_2, int> >));
BOOST_MPL2_ASSERT((not_<is_invocable<_3, int, long> >));
BOOST_MPL2_ASSERT((not_<is_invocable<_4, int, long, long long> >));

template<typename...>
struct wrapper
{
    using type = wrapper;
};

BOOST_MPL2_ASSERT((std::is_same<forward<wrapper, invoke<_>::type>::type, wrapper<> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrapper, invoke<_, short>::type>::type, wrapper<short> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrapper, invoke<_, short, int>::type>::type, wrapper<short, int> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrapper, invoke<_, short, int, long>::type>::type, wrapper<short, int, long> >));
BOOST_MPL2_ASSERT((std::is_same<forward<wrapper, invoke<_, short, int, long, long long>::type>::type, wrapper<short, int, long, long long> >));

BOOST_MPL2_ASSERT((std::is_same<invoke<_1, short, int, long, long long>::type, short>));
BOOST_MPL2_ASSERT((std::is_same<invoke<_2, short, int, long, long long>::type, int>));
BOOST_MPL2_ASSERT((std::is_same<invoke<_3, short, int, long, long long>::type, long>));
BOOST_MPL2_ASSERT((std::is_same<invoke<_4, short, int, long, long long>::type, long long>));

int main()
{
    return 0;
}
