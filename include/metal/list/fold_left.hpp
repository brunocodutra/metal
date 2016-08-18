// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FOLD_LEFT_HPP
#define METAL_LIST_FOLD_LEFT_HPP

namespace metal
{
    namespace detail
    {
        template<typename tabs, typename state, typename lbd>
        struct _fold_cons;

        template<typename seq, typename state, typename lbd>
        struct _fold_left;
    }

    /// \ingroup list
    /// ...
    template<typename seq, typename state, typename lbd>
    using fold_left = typename detail::_fold_left<seq, state, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/value/value.hpp>

namespace metal
{
    namespace detail
    {
        template<typename tabs, typename state, typename lbd, typename = true_>
        struct _fold_cons_impl
        {};

        template<
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p, typename t,
            typename state, template<typename...> class expr
        >
        struct _fold_cons_impl<
            list<a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, t>,
            state,
            lambda<expr>,
            is_value<
                expr<expr<expr<expr<expr<expr<expr<expr<
                    expr<expr<expr<expr<expr<expr<expr<expr<
                        state,
                            a>, b>, c>, d>, e>, f>, g>, h>,
                                i>, j>, k>, l>, m>, n>, o>, p>
            >
        > :
            _fold_cons_impl<
                t,
                expr<expr<expr<expr<expr<expr<expr<expr<
                    expr<expr<expr<expr<expr<expr<expr<expr<
                        state,
                            a>, b>, c>, d>, e>, f>, g>, h>,
                                i>, j>, k>, l>, m>, n>, o>, p>,
                lambda<expr>
            >
        {};

        template<
            typename a, typename b, typename c, typename t,
            typename state, template<typename...> class expr
        >
        struct _fold_cons_impl<list<a, b, c, t>, state, lambda<expr>,
            is_value<expr<expr<expr<state, a>, b>, c>>
        > :
            _fold_cons_impl<t, expr<expr<expr<state, a>, b>, c>, lambda<expr>>
        {};

        template<
            typename a, typename b, typename t,
            typename state, template<typename...> class expr
        >
        struct _fold_cons_impl<list<a, b, t>, state, lambda<expr>,
            is_value<expr<expr<state, a>, b>>
        > :
            _fold_cons_impl<t, expr<expr<state, a>, b>, lambda<expr>>
        {};

        template<
            typename a, typename t,
            typename state, template<typename...> class expr
        >
        struct _fold_cons_impl<list<a, t>, state, lambda<expr>,
            is_value<expr<state, a>>
        > :
            _fold_cons_impl<t, expr<state, a>, lambda<expr>>
        {};

        template<typename state, template<typename...> class expr>
        struct _fold_cons_impl<list<>, state, lambda<expr>>
        {
            using type = state;
        };

        template<typename tabs, typename state, typename lbd>
        struct _fold_cons :
            _fold_cons_impl<tabs, state, lbd>
        {};

        template<typename...>
        struct _cons_left
        {};

        template<typename... vals>
        using cons_left = typename _cons_left<vals...>::type;

        template<
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p, typename... t
        >
        struct _cons_left<a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, t...>
        {
            using type = list<
                a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, cons_left<t...>
            >;
        };

        template<typename a, typename b, typename c, typename... t>
        struct _cons_left<a, b, c, t...>
        {
            using type = list<a, b, c, cons_left<t...>>;
        };

        template<typename a, typename b>
        struct _cons_left<a, b>
        {
            using type = list<a, b, list<>>;
        };

        template<typename a>
        struct _cons_left<a>
        {
            using type = list<a, list<>>;
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
            _fold_cons_impl<cons_left<vals...>, state, lbd>
        {};
    }
}

#endif
