// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MUL_HPP
#define METAL_NUMBER_ARITHMETIC_MUL_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup arithmetic
    /// \brief ...
    template<typename head, typename... tail>
    struct mul;

    /// \ingroup arithmetic
    /// \brief Eager adaptor for \ref mul.
    template<typename head, typename... tail>
    using mul_t = typename mul<head, tail...>::type;

    template<typename x, x xv>
    struct mul<number<x, xv>> :
            number<x, xv>
    {};
    template<typename x, x xv, typename y, y yv, typename... tail>
    struct mul<number<x, xv>, number<y, yv>, tail...> :
            mul<number<decltype(xv * yv), xv * yv>, tail...>
    {};
}

#endif
