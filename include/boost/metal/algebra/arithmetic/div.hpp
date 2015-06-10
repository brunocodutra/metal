/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_ALGEBRA_ARITHMETIC_DIV_HPP
#define BOOST_METAL_ALGEBRA_ARITHMETIC_DIV_HPP

#include <type_traits>

namespace boost
{
    namespace metal
    {
        template<typename x, typename y, typename... _>
        struct div :
                div<div<x, y>, _...>
        {};

        template<typename x, typename y>
        struct div<x, y> :
                std::integral_constant<
                    decltype(x::value / y::value),
                    x::value / y::value
                >
        {};
    }
}

#endif
