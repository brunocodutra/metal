// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_ADD_HPP
#define METAL_NUMBER_ARITHMETIC_ADD_HPP

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename... nums>
    struct add
    {};

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref add.
    template<typename... nums>
    using add_t = typename add<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    template<typename tx, tx vx>
    struct add<number<tx, vx>> :
        number<tx, vx>
    {};

    template<typename tx, tx vx, typename ty, ty vy, typename... nums>
    struct add<number<tx, vx>, number<ty, vy>, nums...> :
        add<number<decltype(vx + vy), vx + vy>, nums...>
    {};
}

#endif
