// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP

#include <metal/config.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq, typename lbd>
        struct _sort;
    }

    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename lbd>
    using sort = typename detail::_sort<seq, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/list/size.hpp>
#include <metal/list/range.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/number/div.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename, typename = true_>
        struct _merge
        {};

        template<
            typename ret,
            typename xh, typename... xt,
            typename yh, typename... yt,
            template<typename...> class expr
        >
        struct _merge<ret, list<xh, xt...>, list<yh, yt...>, lambda<expr>,
            if_<expr<yh, xh>, false_, true_>
        > :
            _merge<
                join<ret, list<xh>>, list<xt...>, list<yh, yt...>, lambda<expr>
            >
        {};

        template<
            typename ret,
            typename xh, typename... xt,
            typename yh, typename... yt,
            template<typename...> class expr
        >
        struct _merge<ret, list<xh, xt...>, list<yh, yt...>, lambda<expr>,
            if_<expr<yh, xh>, true_, false_>
        > :
            _merge<
                join<ret, list<yh>>, list<xh, xt...>, list<yt...>, lambda<expr>
            >
        {};

        template<typename ret, typename seq, typename lbd>
        struct _merge<ret, seq, list<>, lbd> :
            _join<ret, seq>
        {};

        template<typename ret, typename seq, typename lbd>
        struct _merge<ret, list<>, seq, lbd> :
            _join<ret, seq>
        {};

        template<typename ret, typename lbd>
        struct _merge<ret, list<>, list<>, lbd>
        {
            using type = ret;
        };

        template<typename seq, typename lbd>
        using sort_impl = typename _merge<
            list<>,
            sort<range<seq, number<0>, div<size<seq>, number<2>>>, lbd>,
            sort<range<seq, div<size<seq>, number<2>>, size<seq>>, lbd>,
            lbd
        >::type;

        template<typename seq, typename lbd>
        struct _sort :
            _invoke<lambda<sort_impl>, seq, lbd>
        {};

        template<typename x, typename y, typename lbd>
        struct _sort<list<x, y>, lbd> :
            _merge<list<>, list<x>, list<y>, lbd>
        {};

        template<typename x, typename lbd>
        struct _sort<list<x>, lbd> :
            _if_<is_lambda<lbd>, list<x>>
        {};

        template<typename lbd>
        struct _sort<list<>, lbd> :
            _if_<is_lambda<lbd>, list<>>
        {};
    }
}

#endif
