// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REVERSE_HPP
#define METAL_LIST_REVERSE_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct reverse;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using reverse = detail::reverse<list>;

    /// \ingroup list
    /// Eager adaptor for metal::reverse.
    template<typename list>
    using reverse_t = typename metal::reverse<list>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/size.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct reverse
        {};

        template<template<typename...> class expr, typename... vals>
        struct reverse<expr<vals...>> :
            copy<
                expr<vals...>,
                expr<vals...>,
                size_t<expr<vals...>>,
                integer<0>
            >
        {};
    }
}

#endif
