// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct sort;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using sort = detail::sort<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for \ref sort.
    template<typename list, typename lbd>
    using sort_t = typename metal::sort<list, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/reduce.hpp>
#include <metal/list/push_front.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/quote.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = boolean<true>>
        struct merge
        {};

        template<typename... xs, typename lbd>
        struct merge<list<xs...>, list<>, lbd> :
            list<xs...>
        {};

        template<typename... ys, typename lbd>
        struct merge<list<>, list<ys...>, lbd> :
            list<ys...>
        {};

        template<
            typename xh, typename... xt,
            typename yh, typename... yt,
            typename lbd
        >
        struct merge<list<xh, xt...>, list<yh, yt...>, lbd,
            invoke_t<lbd, xh, yh>
        > :
            invoke<
                push_front<merge<_1, _2, quote_t<lbd>>, _3>,
                list<xt...>, list<yh, yt...>, xh
            >
        {};

        template<
            typename xh, typename... xt,
            typename yh, typename... yt,
            typename lbd,
            typename _
        >
        struct merge<list<xh, xt...>, list<yh, yt...>, lbd, _> :
            invoke<
                push_front<merge<_1, _2, quote_t<lbd>>, _3>,
                list<xh, xt...>, list<yt...>, yh
            >
        {};

        template<typename list, typename lbd>
        struct sort
        {};

        template<typename... vals, typename lbd>
        struct sort<list<vals...>, lbd> :
            reduce<list<list<vals>...>, merge<_1, _2, quote_t<lbd>>>
        {};

        template<typename lbd>
        struct sort<list<>, lbd> :
            list<>
        {};

        template<
            template<typename...> class expr,
            typename... vals, typename lbd
        >
        struct sort<expr<vals...>, lbd> :
            invoke<
                copy<_1, sort<_2, _3>>,
                expr<vals...>, list<vals...>, lbd
            >
        {};
    }
}

#endif
