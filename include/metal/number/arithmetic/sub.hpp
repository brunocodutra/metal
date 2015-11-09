// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_SUB_HPP
#define METAL_NUMBER_ARITHMETIC_SUB_HPP

namespace metal
{
    /// \ingroup arithmetic
    /// ...
    template<typename... nums>
    struct sub
    {};

    /// \ingroup arithmetic
    /// Eager adaptor for \ref sub.
    template<typename... nums>
    using sub_t = typename metal::sub<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename tx, tx vx>
    struct sub<number<tx, vx>> :
        number<tx, vx>
    {};

    template<typename tx, tx vx, typename ty, ty vy, typename... nums>
    struct sub<number<tx, vx>, number<ty, vy>, nums...> :
        sub<number<decltype(vx - vy), vx - vy>, nums...>
    {};
}

#endif
