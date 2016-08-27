// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FOLD_LEFT_HPP
#define METAL_LIST_FOLD_LEFT_HPP

namespace metal
{
    namespace detail
    {
        template<typename seq, typename state, typename lbd>
        struct _fold_left;
    }

    /// \ingroup list
    /// ...
    template<typename seq, typename state, typename lbd>
    using fold_left = typename detail::_fold_left<seq, state, lbd>::type;
}

#include <metal/list/list.hpp>

#include <metal/detail/fold_cons.hpp>

namespace metal
{
    namespace detail
    {
        template<typename...>
        struct _cons_left
        {};

        template<typename... vals>
        using cons_left = typename _cons_left<vals...>::type;

        template<
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p, typename... tail
        >
        struct _cons_left<
            a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, tail...
        >
        {
            using type = list<
                a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p,
                cons_left<tail...>
            >;
        };

        template<typename head, typename... tail>
        struct _cons_left<head, tail...>
        {
            using type = list<head, cons_left<tail...>>;
        };

        template<>
        struct _cons_left<>
        {
            using type = list<>;
        };

        template<typename seq, typename state, typename lbd>
        struct _fold_left
        {};

        template<typename... vals, typename state, typename lbd>
        struct _fold_left<list<vals...>, state, lbd> :
            _fold_cons<cons_left<vals...>, state, lbd>
        {};
    }
}

#endif
