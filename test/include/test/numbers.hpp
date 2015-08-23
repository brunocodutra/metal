// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_NUMBERS_HPP
#define METAL_TEST_NUMBERS_HPP

#include <type_traits>
#include <cstddef>

#define _bool(B) std::integral_constant<bool, (B)>
#define _true std::true_type
#define _false std::false_type

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

#define _num(N) _cat(num, N)
#define _nums(N) _enum(N, num)

#endif

