// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_EQUAL_TO_HPP
#define METAL_NUMBER_COMPARISON_EQUAL_TO_HPP

namespace metal
{
    /// \ingroup comparison
    /// ...
    template<typename x, typename y>
    struct equal_to
    {};

    /// \ingroup comparison
    /// Eager adaptor for \ref equal_to.
    template<typename x, typename y>
    using equal_to_t = typename metal::equal_to<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename tx, tx vx, typename ty, ty vy>
    struct equal_to<number<tx, vx>, number<ty, vy>> :
        boolean<(vx == vy)>
    {};
}

#endif
