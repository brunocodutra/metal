// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _join;
    }

    /// \ingroup list
    /// ...
    template<typename head, typename... tail>
    using join = typename detail::_join<head, tail...>::type;
}

#include <metal/list/list.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/list/reduce.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _join
        {};

        template<
            template<typename...> class seq,
            typename... ws, typename... xs, typename... ys, typename... zs,
            typename... _
        >
        struct _join<seq<ws...>, seq<xs...>, seq<ys...>, seq<zs...>, _...> :
            _reduce<
                list<seq<ws...>, seq<xs...>, seq<ys...>, seq<zs...>, _...>,
                lambda<join>,
                size_t<0>, size_t<sizeof...(_) + 4>
            >
        {};

        template<
            template<typename...> class seq,
            typename... ws, typename... xs, typename... ys, typename... zs
        >
        struct _join<seq<ws...>, seq<xs...>, seq<ys...>, seq<zs...>> :
            _invoke<lambda<seq>, ws..., xs..., ys..., zs...>
        {};

        template<
            template<typename...> class seq,
            typename... ws, typename... xs, typename... ys
        >
        struct _join<seq<ws...>, seq<xs...>, seq<ys...>> :
            _invoke<lambda<seq>, ws..., xs..., ys...>
        {};

        template<
            template<typename...> class seq,
            typename... ws, typename... xs
        >
        struct _join<seq<ws...>, seq<xs...>> :
            _invoke<lambda<seq>, ws..., xs...>
        {};

        template<template<typename...> class seq, typename... ws>
        struct _join<seq<ws...>>
        {
            using type = seq<ws...>;
        };
    }
}

#endif
