// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGEBRA_ARITHMETIC_DEC_HPP
#define METAL_ALGEBRA_ARITHMETIC_DEC_HPP

#include <type_traits>

namespace metal
{
    template<typename x>
    struct dec :
            std::integral_constant<
                decltype(x::value),
                static_cast<decltype(x::value)>(x::value - 1)
            >
    {};
}

#endif
