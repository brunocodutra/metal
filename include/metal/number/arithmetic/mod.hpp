// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MOD_HPP
#define METAL_NUMBER_ARITHMETIC_MOD_HPP

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename x, typename y>
    struct mod
    {};

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref mod.
    template<typename x, typename y>
    using mod_t = typename mod<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename tx, tx vx, typename ty, ty vy>
    struct mod<number<tx, vx>, number<ty, vy>> :
        number<decltype(vx % vy), vx % vy>
    {};
}

#endif
