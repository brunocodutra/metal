/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_INTEGRALS_HPP
#define METAL_TEST_INTEGRALS_HPP

#include <type_traits>

namespace test
{
    using zero = std::integral_constant<char, 0>;
    using one = std::integral_constant<signed char, 1>;
    using two = std::integral_constant<short, 2>;
    using three = std::integral_constant<int, 3>;
    using four = std::integral_constant<long, 4>;
    using five = std::integral_constant<long long, 5>;
    using six = std::integral_constant<unsigned char, 6>;
    using seven = std::integral_constant<unsigned short, 7>;
    using eight = std::integral_constant<unsigned int, 8>;
    using nine = std::integral_constant<unsigned long, 9>;
    using ten = std::integral_constant<unsigned long long, 10>;
}

#endif
