// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGEBRA_ARITHMETIC_SUB_HPP
#define METAL_ALGEBRA_ARITHMETIC_SUB_HPP

#include <type_traits>

namespace metal
{
    ///\cond
    template<typename head, typename... tail>
    struct sub;

    template<typename x>
    struct sub<x> :
            std::integral_constant<decltype(x::value), x::value>
    {};

    template<typename x, typename y, typename... tail>
    struct sub<x, y, tail...> :
            sub<sub<x, y>, tail...>
    {};

    template<typename x, typename y>
    struct sub<x, y> :
            std::integral_constant<
                decltype(x::value - y::value),
                x::value - y::value
            >
    {};
    ///\endcond

    template<typename head, typename... tail>
    using sub_t = typename sub<head, tail...>::type;
}

#endif
