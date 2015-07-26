// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGEBRA_ARITHMETIC_ADD_HPP
#define METAL_ALGEBRA_ARITHMETIC_ADD_HPP

#include <type_traits>

namespace metal
{
    ///\cond
    template<typename head, typename... tail>
    struct add :
            add<head, add<tail...>>
    {};

    template<typename x>
    struct add<x> :
            std::integral_constant<decltype(x::value), x::value>
    {};

    template<typename x, typename y>
    struct add<x, y> :
            std::integral_constant<
                decltype(x::value + y::value),
                x::value + y::value
            >
    {};
    ///\endcond

    template<typename head, typename... tail>
    using add_t = typename add<head, tail...>::type;
}

#endif
