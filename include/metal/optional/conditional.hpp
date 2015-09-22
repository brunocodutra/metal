// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_CONDITIONAL_HPP
#define METAL_OPTIONAL_CONDITIONAL_HPP

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename...>
    struct conditional
    {};

    /// \ingroup optional
    /// \brief Eager adaptor for \ref conditional.
    template<typename... args>
    using conditional_t = typename metal::conditional<args...>::type;
}

#include <metal/optional/eval.hpp>
#include <metal/optional/nothing.hpp>
#include <metal/optional/optional.hpp>
#include <metal/number/number.hpp>

#include <type_traits>

namespace metal
{
    template<typename pred1, typename then1, typename pred2, typename then2, typename... else_>
    struct conditional<pred1, then1, pred2, then2, else_...> :
        conditional<pred1, then1, conditional<pred2, then2, else_...>>
    {};

    template<typename t, t v, typename then, typename else_>
    struct conditional<number<t, v>, then, else_> :
        optional<eval<std::conditional<static_cast<bool>(v), then, else_>>>
    {};

    template<typename pred, typename then>
    struct conditional<pred, then> :
        conditional<pred, then, nothing>
    {};
}

#endif
