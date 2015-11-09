// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MUL_HPP
#define METAL_NUMBER_ARITHMETIC_MUL_HPP

namespace metal
{
    /// \ingroup arithmetic
    /// ...
    template<typename... nums>
    struct mul
    {};

    /// \ingroup arithmetic
    /// Eager adaptor for \ref mul.
    template<typename... nums>
    using mul_t = typename metal::mul<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename tx, tx vx>
    struct mul<number<tx, vx>> :
        number<tx, vx>
    {};

    template<typename tx, tx vx, typename ty, ty vy, typename... nums>
    struct mul<number<tx, vx>, number<ty, vy>, nums...> :
        mul<number<decltype(vx * vy), vx * vy>, nums...>
    {};
}

#endif
