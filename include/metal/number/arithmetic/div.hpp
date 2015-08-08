// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_DIV_HPP
#define METAL_NUMBER_ARITHMETIC_DIV_HPP

#include <metal/number/number.hpp>

namespace metal
{
    template<typename head, typename... tail>
    struct div;

    template<typename head, typename... tail>
    using div_t = typename div<head, tail...>::type;

    template<typename x, x xv>
    struct div<number<x, xv>> :
            number<x, xv>
    {};
    template<typename x, x xv, typename y, y yv, typename... tail>
    struct div<number<x, xv>, number<y, yv>, tail...> :
            div<number<decltype(xv / yv), xv / yv>, tail...>
    {};
}

#endif
