// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_TEST_INTEGRALS_HPP
#define BOOST_MPL2_TEST_INTEGRALS_HPP

#include <type_traits>

namespace test
{
    typedef std::integral_constant<short, 0> zero;
    typedef std::integral_constant<int, 1> one;
    typedef std::integral_constant<long, 2> two;
    typedef std::integral_constant<long long, 3> three;
    typedef std::integral_constant<unsigned short, 4> four;
    typedef std::integral_constant<unsigned int, 5> five;
    typedef std::integral_constant<unsigned long, 6> six;
    typedef std::integral_constant<unsigned long long, 7> seven;
}

#endif
