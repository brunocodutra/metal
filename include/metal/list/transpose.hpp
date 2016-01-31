// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_TRANSPOSE_HPP
#define METAL_LIST_TRANSPOSE_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct transpose;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using transpose = detail::transpose<list>;

    /// \ingroup list
    /// Eager adaptor for \ref transpose.
    template<typename list>
    using transpose_t = typename metal::transpose<list>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/list/same.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename>
        struct unbind
        {};

        template<typename list>
        using unbind_t = typename unbind<list>::type;

        template<template<typename...> class expr, typename... vals>
        struct unbind<expr<vals...>>
        {
            using type = lambda<expr>;
        };

        template<
            typename,
            typename = boolean<true>,
            typename = boolean<true>,
            typename = boolean<true>
        >
        struct transpose_impl
        {};

        template<
            template<typename...> class outer,
            typename head, typename... tail
        >
        struct transpose_impl<
            outer<head, tail...>,
            same_t<outer<size_t<head>, size_t<tail>...>>,
            same_t<outer<unbind_t<head>, unbind_t<tail>...>>,
            boolean<(sizeof...(tail) > 1)>
        > :
            transform<
                indices_t<head>,
                defer_t<outer<at<quote_t<head>, _1>, at<quote_t<tail>, _1>...>>
            >
        {};

        template<
            template<typename...> class outer,
            template<typename...> class inner,
            typename... xs, typename... ys
        >
        struct transpose_impl<
            outer<inner<xs...>, inner<ys...>>,
            boolean<sizeof...(xs) == sizeof...(ys)>
        >
        {
            using type = inner<outer<xs, ys>...>;
        };

        template<typename list>
        struct transpose :
            transpose_impl<list>
        {};

        template<
            template<typename...> class outer,
            template<typename...> class inner,
            typename... xs
        >
        struct transpose<outer<inner<xs...>>>
        {
            using type = inner<outer<xs>...>;
        };
    }
}

#endif
