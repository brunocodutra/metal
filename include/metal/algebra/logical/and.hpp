// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGEBRA_LOGICAL_AND_HPP
#define METAL_ALGEBRA_LOGICAL_AND_HPP

#include <type_traits>

namespace metal
{
    ///\cond
    template<typename head, typename... tail>
    struct and_ :
            and_<head, and_<tail...>>
    {};

    template<typename x>
    struct and_<x> :
            std::integral_constant<bool, !!x::value>
    {};

    template<typename x, typename y>
    struct and_<x, y> :
            and_<std::integral_constant<bool, !!x::value>, y>
    {};

    template<typename y> struct and_<std::true_type, y> : y {};
    template<typename y> struct and_<std::false_type, y> : std::false_type {};
    ///\endcond

    template<typename head, typename... tail>
    using and_t = typename and_<head, tail...>::type;
}

#endif
