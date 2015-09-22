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
    template<typename x, x xv>
    struct div<number<x, xv>> :
        number<x, xv>
    {};

    template<typename x, x xv, typename y, y yv, typename... nums>
    struct div<number<x, xv>, number<y, yv>, nums...> :
        div<number<decltype(xv / yv), xv / yv>, nums...>
    {};
}

#endif
