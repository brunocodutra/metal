// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_INTEGRALS_HPP
#define METAL_TEST_INTEGRALS_HPP

#include <type_traits>

namespace test
{
    using _0 = std::integral_constant<signed char, 0>;
    using _1 = std::integral_constant<short, 1>;
    using _2 = std::integral_constant<int, 2>;
    using _3 = std::integral_constant<long, 3>;
    using _4 = std::integral_constant<long long, 4>;
    using _5 = std::integral_constant<unsigned char, 5>;
    using _6 = std::integral_constant<unsigned short, 6>;
    using _7 = std::integral_constant<unsigned int, 7>;
    using _8 = std::integral_constant<unsigned long, 8>;
    using _9 = std::integral_constant<unsigned long long, 9>;
}

#endif
