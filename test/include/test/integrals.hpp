// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_INTEGRALS_HPP
#define METAL_TEST_INTEGRALS_HPP

#include <type_traits>

namespace test
{
    using _00_ = std::integral_constant<char, 0>;
    using _01_ = std::integral_constant<signed char, 1>;
    using _02_ = std::integral_constant<short, 2>;
    using _03_ = std::integral_constant<int, 3>;
    using _04_ = std::integral_constant<long, 4>;
    using _05_ = std::integral_constant<long long, 5>;
    using _06_ = std::integral_constant<unsigned char, 6>;
    using _07_ = std::integral_constant<unsigned short, 7>;
    using _08_ = std::integral_constant<unsigned int, 8>;
    using _09_ = std::integral_constant<unsigned long, 9>;
    using _10_ = std::integral_constant<unsigned long long, 10>;
}

#endif
