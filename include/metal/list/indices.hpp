// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_INDICES_HPP
#define METAL_LIST_INDICES_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct indices;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using indices = detail::indices<list>;

    /// \ingroup list
    /// Eager adaptor for \ref indices.
    template<typename list>
    using indices_t = typename metal::indices<list>::type;
}

#include <metal/list/size.hpp>
#include <metal/list/copy.hpp>
#include <metal/number/enumerate.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct indices
        {};

        template<template<typename...> class expr, typename... vals>
        struct indices<expr<vals...>> :
            copy<expr<vals...>, enumerate_t<size_t<expr<vals...>>>>
        {};
    }
}

#endif
