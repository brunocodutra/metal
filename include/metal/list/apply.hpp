// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_APPLY_HPP
#define METAL_LIST_APPLY_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename list>
        struct apply;
    }

    /// \ingroup list
    /// ...
    template<typename lbd, typename list>
    using apply = detail::apply<lbd, list>;

    /// \ingroup list
    /// Eager adaptor for metal::apply.
    template<typename lbd, typename list>
    using apply_t = typename metal::apply<lbd, list>::type;
}

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename list>
        struct apply
        {};

        template<
            typename lbd,
            template<typename...> class expr, typename... vals
        >
        struct apply<lbd, expr<vals...>> :
            invoke<lbd, vals...>
        {};

        template<template<typename...> class expr, typename... vals>
        struct apply<lambda<expr>, expr<vals...>> :
            optional<expr<vals...>>
        {};
    }
}

#endif
