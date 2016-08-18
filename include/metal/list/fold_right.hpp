// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FOLD_RIGHT_HPP
#define METAL_LIST_FOLD_RIGHT_HPP

namespace metal
{
    namespace detail
    {
        template<typename seq, typename state, typename lbd>
        struct _fold_right;
    }

    /// \ingroup list
    /// ...
    template<typename seq, typename state, typename lbd>
    using fold_right = typename detail::_fold_right<seq, state, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/fold_left.hpp>
#include <metal/value/value.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct _cons_right
        {};

        template<typename... vals>
        using cons_right = typename _cons_right<vals...>::type;

        template<
            typename _,
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p, typename... t
        >
        struct _cons_right<
            _, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, t...
        >
        {
            using type = cons_right<
                list<p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a, _>, t...
            >;
        };

        template<typename _, typename a, typename b, typename c, typename... t>
        struct _cons_right<_, a, b, c, t...>
        {
            using type = cons_right<list<c, b, a, _>, t...>;
        };

        template<typename _, typename a, typename b>
        struct _cons_right<_, a, b>
        {
            using type = list<b, a, _>;
        };

        template<typename _, typename a>
        struct _cons_right<_, a>
        {
            using type = list<a, _>;
        };

        template<typename _>
        struct _cons_right<_>
        {
            using type = _;
        };

        template<typename seq, typename state, typename lbd>
        struct _fold_right
        {};

        template<typename... vals, typename state, typename lbd>
        struct _fold_right<list<vals...>, state, lbd> :
            _fold_cons<cons_right<list<>, vals...>, state, lbd>
        {};
    }
}

#endif
