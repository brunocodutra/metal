// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_DIV_HPP
#define METAL_NUMBER_ARITHMETIC_DIV_HPP

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename... nums>
    struct div
    {};

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref div.
    template<typename... nums>
    using div_t = typename div<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename tx, tx vx>
    struct div<number<tx, vx>> :
        number<tx, vx>
    {};

    template<typename tx, tx vx, typename ty, ty vy, typename... nums>
    struct div<number<tx, vx>, number<ty, vy>, nums...> :
        div<number<decltype(vx / vy), vx / vy>, nums...>
    {};
}

#endif
