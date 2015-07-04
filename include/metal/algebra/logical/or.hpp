/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGEBRA_LOGICAL_OR_HPP
#define METAL_ALGEBRA_LOGICAL_OR_HPP

#include <type_traits>

namespace metal
{
    template<typename x, typename y, typename... _>
    struct or_ :
            or_<x, or_<y, _...>>
    {};

    template<typename x, typename y>
    struct or_<x, y> :
            or_<std::integral_constant<bool, !!x::value>, y>
    {};

    template<typename y> struct or_<std::false_type, y> : y {};
    template<typename y> struct or_<std::true_type, y> : std::true_type {};
}

#endif
