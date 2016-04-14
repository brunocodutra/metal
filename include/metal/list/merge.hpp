// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_MERGE_HPP
#define METAL_LIST_MERGE_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... lists>
        struct merge;
    }

    /// \ingroup list
    /// ...
    template<typename lbd, typename... lists>
    using merge = detail::merge<lbd, lists...>;

    /// \ingroup list
    /// Eager adaptor for metal::merge.
    template<typename lbd, typename... lists>
    using merge_t = typename metal::merge<lbd, lists...>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/reduce.hpp>
#include <metal/list/partition.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/pair/first.hpp>
#include <metal/pair/second.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/optional/optional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = boolean<true>>
        struct merge_impl
        {};

        template<
            typename lbd,
            typename xh, typename... xt,
            typename yh, typename... yt
        >
        struct merge_impl<lbd, list<xh, xt...>, list<yh, yt...>,
            invoke_t<lbd, xh, yh>
        > :
            invoke<
                join<
                    _1, first<optional<_4>>, _2,
                    merge_impl<_3, second<optional<_4>>, _5>
                >,
                list<xh>,
                list<yh>,
                lbd,
                partition<list<xt...>, bind_t<lbd, _1, yh>>,
                list<yt...>
            >
        {};

        template<
            typename lbd,
            typename xh, typename... xt,
            typename yh, typename... yt
        >
        struct merge_impl<lbd, list<xh, xt...>, list<yh, yt...>,
            not_t<invoke_t<lbd, xh, yh>>
        > :
            invoke<
                join<
                    _1, first<optional<_5>>, _2,
                    merge_impl<_3, _4, second<optional<_5>>>
                >,
                list<yh>,
                list<xh>,
                lbd,
                list<xt...>,
                partition<list<yt...>, bind_t<lbd, _1, xh>>
            >
        {};

        template<typename lbd, typename xh, typename yh>
        struct merge_impl<lbd, list<xh>, list<yh>,
            invoke_t<lbd, xh, yh>
        > :
            list<xh, yh>
        {};

        template<typename lbd, typename xh, typename yh>
        struct merge_impl<lbd, list<xh>, list<yh>,
            not_t<invoke_t<lbd, xh, yh>>
        > :
            list<yh, xh>
        {};

        template<typename lbd, typename... xs>
        struct merge_impl<lbd, list<xs...>, list<>> :
            list<xs...>
        {};

        template<typename lbd, typename... ys>
        struct merge_impl<lbd, list<>, list<ys...>> :
            list<ys...>
        {};

        template<typename lbd>
        struct merge_impl<lbd, list<>, list<>> :
            list<>
        {};

        template<typename lbd, typename... lists>
        struct merge :
            reduce<list<lists...>, merge<quote_t<lbd>, _1, _2>>
        {};

        template<
            typename lbd,
            template<typename...> class expr,
            typename... xs, typename... ys
        >
        struct merge<lbd, expr<xs...>, expr<ys...>> :
            invoke<
                copy<_1, merge_impl<_2, _3, _4>>,
                expr<xs...>, lbd, list<xs...>, list<ys...>
            >
        {
            using type = expr<xs...>;
        };

        template<typename lbd, typename... xs, typename... ys>
        struct merge<lbd, list<xs...>, list<ys...>> :
            merge_impl<lbd, list<xs...>, list<ys...>>
        {};

        template<typename lbd, typename x, typename y>
        struct merge<lbd, x, y>
        {};
    }
}

#endif
