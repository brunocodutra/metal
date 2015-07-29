// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_NUMBERS_HPP
#define METAL_TEST_NUMBERS_HPP

#include <type_traits>

namespace test
{
    template<int v>
    using number = std::integral_constant<int, v>;

    using n0 = std::integral_constant<signed char, 0>;
    using n1 = std::integral_constant<short, 1>;
    using n2 = std::integral_constant<int, 2>;
    using n3 = std::integral_constant<long, 3>;
    using n4 = std::integral_constant<long long, 4>;
    using n5 = std::integral_constant<unsigned char, 5>;
    using n6 = std::integral_constant<unsigned short, 6>;
    using n7 = std::integral_constant<unsigned int, 7>;
    using n8 = std::integral_constant<unsigned long, 8>;
    using n9 = std::integral_constant<unsigned long long, 9>;
}

#endif
