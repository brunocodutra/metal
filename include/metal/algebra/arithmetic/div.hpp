// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGEBRA_ARITHMETIC_DIV_HPP
#define METAL_ALGEBRA_ARITHMETIC_DIV_HPP

#include <type_traits>

namespace metal
{
    ///\cond
    template<typename head, typename... tail>
    struct div;

    template<typename x>
    struct div<x> :
            std::integral_constant<decltype(x::value), x::value>
    {};

    template<typename x, typename y, typename... tail>
    struct div<x, y, tail...> :
            div<div<x, y>, tail...>
    {};

    template<typename x, typename y>
    struct div<x, y> :
            std::integral_constant<
                decltype(x::value / y::value),
                x::value / y::value
            >
    {};
    ///\endcond

    template<typename head, typename... tail>
    using div_t = typename div<head, tail...>::type;
}

#endif
