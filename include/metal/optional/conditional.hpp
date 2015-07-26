// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_IF_HPP
#define METAL_OPTIONAL_IF_HPP

#include <metal/optional/nothing.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/maybe.hpp>

#include <type_traits>

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename pred, typename then, typename... else_>
    struct if_;

    /// \ingroup optional
    /// \brief Eager adaptor for \ref if_.
    template<typename pred, typename then, typename... else_>
    using conditional_t = typename metal::if_<pred, then, else_...>::type;

    template<typename pred1, typename then1, typename pred2, typename then2, typename... else_>
    struct if_<pred1, then1, pred2, then2, else_...> :
            if_<pred1, then1, if_<pred2, then2, else_...>>
    {};

    template<typename pred, typename then, typename else_>
    struct if_<pred, then, else_> :
            maybe<
                typename std::conditional<!!pred::value, then, else_>::type
            >
    {};

    template<typename pred, typename then>
    struct if_<pred, then> :
            if_<pred, then, just<nothing>>
    {};
}

#endif
