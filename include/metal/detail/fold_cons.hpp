// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_DETAIL_FOLD_CONS_HPP
#define METAL_DETAIL_FOLD_CONS_HPP

#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

namespace metal
{
    namespace detail
    {
        template<typename cons, typename state, typename lbd, typename = true_>
        struct _fold_cons
        {};

        template<
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p, typename tail,
            typename state, template<typename...> class expr
        >
        struct _fold_cons<
            list<a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, tail>,
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
            _fold_cons<
                tail,
                expr<expr<expr<expr<expr<expr<expr<expr<
                    expr<expr<expr<expr<expr<expr<expr<expr<
                        state,
                            a>, b>, c>, d>, e>, f>, g>, h>,
                                i>, j>, k>, l>, m>, n>, o>, p>,
                lambda<expr>
            >
        {};

        template<
            typename head, typename tail,
            typename state, template<typename...> class expr
        >
        struct _fold_cons<list<head, tail>, state, lambda<expr>,
            is_value<expr<state, head>>
        > :
            _fold_cons<tail, expr<state, head>, lambda<expr>>
        {};

        template<typename state, template<typename...> class expr>
        struct _fold_cons<list<>, state, lambda<expr>>
        {
            using type = state;
        };
    }
}

#endif

