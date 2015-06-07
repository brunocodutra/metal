// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_ALGEBRA_LOGICAL_AND_HPP
#define BOOST_METAL_ALGEBRA_LOGICAL_AND_HPP

#include <type_traits>

namespace boost
{
    namespace metal
    {
        template<typename x, typename y, typename... _>
        struct and_ :
                and_<x, and_<y, _...>>
        {};

        template<typename x, typename y>
        struct and_<x, y> :
                and_<std::integral_constant<bool, !!x::value>, y>
        {};

        template<typename y> struct and_<std::true_type, y> : y {};
        template<typename y> struct and_<std::false_type, y> : std::false_type {};
    }
}

#endif
