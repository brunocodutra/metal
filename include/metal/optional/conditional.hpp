// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_CONDITIONAL_HPP
#define METAL_OPTIONAL_CONDITIONAL_HPP

namespace metal
{
    /// \ingroup optional
    /// ...
    template<typename if_, typename then, typename... else_>
    struct conditional
    {};

    /// \ingroup optional
    /// Eager adaptor for \ref conditional.
    template<typename if_, typename then, typename... else_>
    using conditional_t = typename metal::conditional<if_, then, else_...>::type;
}

#include <metal/optional/optional.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    template<
        typename if1, typename then1,
        typename if2, typename then2,
        typename... else_
    >
    struct conditional<if1, then1, if2, then2, else_...> :
        conditional<if1, then1, conditional<if2, then2, else_...>>
    {};

    template<typename if_, typename then>
    struct conditional<if_, then> :
        conditional<if_, then, nothing>
    {};

    template<typename t, t v, typename then, typename else_>
    struct conditional<number<t, v>, then, else_> :
        conditional<boolean<v && true>, then, else_>
    {};

    template<typename then, typename else_>
    struct conditional<boolean<true>, then, else_> :
        optional<then>
    {};

    template<typename then, typename else_>
    struct conditional<boolean<false>, then, else_> :
        optional<else_>
    {};
}

#endif
