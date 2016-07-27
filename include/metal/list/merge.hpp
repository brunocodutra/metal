// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_MERGE_HPP
#define METAL_LIST_MERGE_HPP

#include <metal/list/list.hpp>
#include <metal/list/unwrap.hpp>
#include <metal/list/reduce.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/number.hpp>
#include <metal/number/and.hpp>
#include <metal/number/if.hpp>
#include <metal/value/equal.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = true_>
        struct _merge_impl;

        template<typename lbd, typename x, typename y>
        using merge_impl = typename _merge_impl<lbd, x, y>::type;
    }

    /// \ingroup list
    /// ...
    template<typename lbd, typename head, typename... tail>
    using merge = apply<
        if_<and_<equal<unwrap<head>, unwrap<tail>>...>, unwrap<head>>,
        reduce<
            list<apply<lambda<list>, head>, apply<lambda<list>, tail>...>,
            partial<lambda<detail::merge_impl>, if_<is_lambda<lbd>, lbd>>
        >
    >;
}

#include <metal/list/join.hpp>
#include <metal/list/copy_if.hpp>
#include <metal/list/remove_if.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/not.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename lbd,
            typename xh, typename xt,
            typename yh, typename yt
        >
        using merge_impl_recurse = join<
            list<xh>,
            remove_if<xt, partial<lbd, yh>>,
            list<yh>,
            merge_impl<lbd, copy_if<xt, partial<lbd, yh>>, yt>
        >;

        template<typename, typename, typename, typename>
        struct _merge_impl
        {};

        template<
            template<template<typename...> class> class lbd,
            template<typename...> class expr,
            typename xh, typename... xt,
            typename yh, typename... yt
        >
        struct _merge_impl<lbd<expr>, list<xh, xt...>, list<yh, yt...>,
            not_<expr<yh, xh>>
        > :
            _invoke<
                lbd<merge_impl_recurse>,
                lbd<expr>, xh, list<xt...>, yh, list<yt...>
            >
        {};

        template<
            template<template<typename...> class> class lbd,
            template<typename...> class expr,
            typename xh, typename... xt,
            typename yh, typename... yt
        >
        struct _merge_impl<lbd<expr>, list<xh, xt...>, list<yh, yt...>,
            not_<not_<expr<yh, xh>>>
        > :
            _invoke<
                lbd<merge_impl_recurse>,
                lbd<expr>, yh, list<yt...>, xh, list<xt...>
            >
        {};

        template<typename lbd, typename... vals>
        struct _merge_impl<lbd, list<vals...>, list<>>
        {
            using type = list<vals...>;
        };

        template<typename lbd, typename... vals>
        struct _merge_impl<lbd, list<>, list<vals...>>
        {
            using type = list<vals...>;
        };

        template<typename lbd>
        struct _merge_impl<lbd, list<>, list<>>
        {
            using type = list<>;
        };
    }
}

#endif
