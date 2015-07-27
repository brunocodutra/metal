// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_CONDITIONAL_HPP
#define METAL_OPTIONAL_CONDITIONAL_HPP

#include <metal/optional/nothing.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/maybe.hpp>

#include <type_traits>

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename pred, typename then, typename... else_>
    struct conditional;

    /// \ingroup optional
    /// \brief Eager adaptor for \ref conditional.
    template<typename pred, typename then, typename... else_>
    using conditional_t = typename metal::conditional<pred, then, else_...>::type;

    template<typename pred1, typename then1, typename pred2, typename then2, typename... else_>
    struct conditional<pred1, then1, pred2, then2, else_...> :
            conditional<pred1, then1, conditional<pred2, then2, else_...>>
    {};

    template<typename pred, typename then, typename else_>
    struct conditional<pred, then, else_> :
            maybe<
                typename std::conditional<!!pred::value, then, else_>::type
            >
    {};

    template<typename pred, typename then>
    struct conditional<pred, then> :
            conditional<pred, then, just<nothing>>
    {};
}

#endif
