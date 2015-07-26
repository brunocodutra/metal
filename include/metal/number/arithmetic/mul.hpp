// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MUL_HPP
#define METAL_NUMBER_ARITHMETIC_MUL_HPP

#include <type_traits>

namespace metal
{
    ///\cond
    template<typename head, typename... tail>
    struct mul :
            mul<head, mul<tail...>>
    {};

    template<typename x>
    struct mul<x> :
            std::integral_constant<decltype(x::value), x::value>
    {};

    template<typename x, typename y>
    struct mul<x, y> :
            std::integral_constant<
                decltype(x::value * y::value),
                x::value * y::value
            >
    {};
    ///\endcond

    template<typename head, typename... tail>
    using mul_t = typename mul<head, tail...>::type;
}

#endif
