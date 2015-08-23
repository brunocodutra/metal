// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/lambda/arg.hpp>
#include <metal/expression/eval.hpp>
#include <metal/list/list.hpp>
#include <metal/list/at.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct apply;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref apply.
    template<typename... args>
    using apply_t = typename apply<args...>::type;

    namespace detail
    {
        template<template<typename...> class expr>
        struct lift
        {
            template<typename... opts>
            using type = expr<from_just<opts>...>;
        };
    }

    template<typename val, typename... args>
    struct apply<val, args...>
    {
        using type = val;
    };

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct apply<expr<params...>, args...> :
            eval<
                detail::lift<expr>::template type,
                apply<params, args...>...
            >
    {};

    template<std::size_t n, typename... args>
    struct apply<arg<n>, args...> :
            conditional<
                boolean<n <= sizeof...(args)>,
                at<list<args...>, number<std::size_t, n - 1>>
            >
    {};

    template<typename... args>
    struct apply<arg<0U>, args...>
    {};
}

#endif
