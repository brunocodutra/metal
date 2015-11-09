// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_OR_HPP
#define METAL_NUMBER_LOGICAL_OR_HPP

namespace metal
{
    /// \ingroup logical
    /// ...
    template<typename... nums>
    struct or_;

    /// \ingroup logical
    /// Eager adaptor for \ref or_.
    template<typename... nums>
    using or_t = typename metal::or_<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/number/logical/and.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    template<typename... nums>
    struct or_ :
        conditional<and_t<is_number_t<nums>...>, boolean<true>>
    {};

    template<typename tx, tx vx, typename ty, ty vy, typename... tail>
    struct or_<number<tx, vx>, number<ty, vy>, number<tail, false>...> :
        boolean<vx || vy>
    {};

    template<typename t, t v>
    struct or_<number<t, v>> :
        boolean<v || false>
    {};

    template<>
    struct or_<> :
        boolean<false>
    {};
}

#endif
