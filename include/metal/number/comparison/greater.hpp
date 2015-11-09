// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_GREATER_HPP
#define METAL_NUMBER_COMPARISON_GREATER_HPP

namespace metal
{
    /// \ingroup comparison
    /// ...
    template<typename x, typename y>
    struct greater
    {};

    /// \ingroup comparison
    /// Eager adaptor for \ref greater.
    template<typename x, typename y>
    using greater_t = typename metal::greater<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename tx, tx vx, typename ty, ty vy>
    struct greater<number<tx, vx>, number<ty, vy>> :
        boolean<(vx > vy)>
    {};
}

#endif
