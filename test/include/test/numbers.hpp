// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_NUMBERS_HPP
#define METAL_TEST_NUMBERS_HPP

#include <type_traits>
#include <cstddef>

namespace test
{
    using num0  = std::integral_constant<signed char, 0>;
    using num1  = std::integral_constant<short, 1>;
    using num2  = std::integral_constant<int, 2>;
    using num3  = std::integral_constant<long, 3>;
    using num4  = std::integral_constant<long long, 4>;
    using num5  = std::integral_constant<unsigned char, 5>;
    using num6  = std::integral_constant<unsigned short, 6>;
    using num7  = std::integral_constant<unsigned int, 7>;
    using num8  = std::integral_constant<unsigned long, 8>;
    using num9  = std::integral_constant<unsigned long long, 9>;
    using num10 = std::integral_constant<std::size_t, 10>;
}

#define NUM(N) CAT(test::num, N)
#define NUMS(N) ENUM(N, test::num)

#define BOOL(B) std::integral_constant<bool, (B)>
#define TRUE std::true_type
#define FALSE std::false_type

#endif

