// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/eval.hpp>

#include "test.hpp"

using namespace boost::mpl2;

template<typename = void>
struct e0 :
        test::wrap<>
{};

template<typename x>
struct e1 :
        test::wrap<x>
{};

template<typename x, typename y>
struct e2 :
        test::wrap<x, y>
{};

template<typename... args>
struct en :
        test::wrap<args...>
{};

BOOST_MPL2_ASSERT((std::is_same<eval<e0>::type, e0<>::type>));
BOOST_MPL2_ASSERT((std::is_same<eval<e1, void>::type, e1<void>::type>));
BOOST_MPL2_ASSERT((std::is_same<eval<e2, void, void*>::type, e2<void, void*>::type>));

BOOST_MPL2_ASSERT((std::is_same<eval<en>::type, en<>::type>));
BOOST_MPL2_ASSERT((std::is_same<eval<en, short>::type, en<short>::type>));
BOOST_MPL2_ASSERT((std::is_same<eval<en, short, int>::type, en<short, int>::type>));
BOOST_MPL2_ASSERT((std::is_same<eval<en, short, int, long>::type, en<short, int, long>::type>));
BOOST_MPL2_ASSERT((std::is_same<eval<en, short, int, long, long long>::type, en<short, int, long, long long>::type>));

int main()
{
    return 0;
}

