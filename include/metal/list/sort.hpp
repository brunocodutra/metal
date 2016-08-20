// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP

#include <metal/lambda/lambda.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq, typename lbd>
        struct _sort;
    }

    /// \ingroup list
    /// ...
    template<typename seq, typename lbd>
    using sort = typename detail::_sort<seq, if_<is_lambda<lbd>, lbd>>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/list/drop.hpp>
#include <metal/list/take.hpp>
#include <metal/list/copy_if.hpp>
#include <metal/list/remove_if.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/number.hpp>
#include <metal/number/div.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename x, typename y>
        struct _merge;

        template<typename lbd, typename x, typename y>
        using merge = typename _merge<lbd, x, y>::type;

        template<typename lbd, typename x, typename xh, typename y, typename yh>
        using merge_impl = join<
            remove_if<x, partial<lbd, yh>>,
            remove_if<y, partial<lbd, xh>>,
            merge<
                lbd,
                copy_if<x, partial<lbd, yh>>,
                copy_if<y, partial<lbd, xh>>
            >
        >;

        template<typename lbd, typename x, typename y>
        struct _merge
        {};

        template<
            typename lbd,
            typename xh, typename... xt,
            typename yh, typename... yt
        >
        struct _merge<lbd, list<xh, xt...>, list<yh, yt...>> :
            _invoke<
                lambda<merge_impl>,
                lbd, list<xh, xt...>, xh, list<yh, yt...>, yh
            >
        {};

        template<typename lbd, typename seq>
        struct _merge<lbd, seq, list<>>
        {
            using type = seq;
        };

        template<typename lbd, typename seq>
        struct _merge<lbd, list<>, seq>
        {
            using type = seq;
        };

        template<typename lbd>
        struct _merge<lbd, list<>, list<>>
        {
            using type = list<>;
        };

        template<typename seq, typename lbd>
        using sort_impl = merge<
            lbd,
            sort<take<seq, div<size<seq>, number<2>>>, lbd>,
            sort<drop<seq, div<size<seq>, number<2>>>, lbd>
        >;

        template<typename seq, typename lbd>
        struct _sort :
            _invoke<lambda<sort_impl>, seq, lbd>
        {};

        template<typename val, typename lbd>
        struct _sort<list<val>, lbd>
        {
            using type = list<val>;
        };

        template<typename lbd>
        struct _sort<list<>, lbd>
        {
            using type = list<>;
        };
    }
}

#endif
