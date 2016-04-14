// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_EMPTY_HPP
#define METAL_LIST_EMPTY_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct empty;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using empty = detail::empty<list>;

    /// \ingroup list
    /// Eager adaptor for metal::empty.
    template<typename list>
    using empty_t = typename metal::empty<list>::type;
}

#include <metal/list/size.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct empty
        {};

        template<template<typename...> class expr, typename... vals>
        struct empty<expr<vals...>> :
            not_<size_t<expr<vals...>>>
        {};
    }
}

#endif
