// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

#include <metal/config.hpp>

#include <metal/list/list.hpp>
#include <metal/number/if.hpp>
#include <metal/number/and.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _join;

        template<typename head, typename... tail>
        using join = typename _join<head, tail...>::type;
    }

    /// \ingroup list
    /// ...
    template<typename head, typename... tail>
    using join = typename if_<
        and_<is_list<head>, is_list<tail>...>,
        detail::_join<head, tail...>
    >::type;

    namespace detail
    {
        template<typename head, typename... tail>
        struct _join_impl
        {};

        template<typename head, typename... tail>
        using join_impl = typename _join_impl<head, tail...>::type;

        template<
            typename... a, typename... b, typename... c, typename... d,
            typename... e, typename... f, typename... g, typename... h,
            typename... i, typename... j, typename... k, typename... l,
            typename... m, typename... n, typename... o, typename... p,
            typename... tail
        >
        struct _join_impl<
            list<a...>, list<b...>, list<c...>, list<d...>,
            list<e...>, list<f...>, list<g...>, list<h...>,
            list<i...>, list<j...>, list<k...>, list<l...>,
            list<m...>, list<n...>, list<o...>, list<p...>,
            tail...
        > :
            _join<
                list<
                    a..., b..., c..., d..., e..., f..., g..., h...,
                    i..., j..., k..., l..., m..., n..., o..., p...
                >,
                tail...
            >
        {};

        template<typename... a, typename... b>
        struct _join_impl<list<a...>, list<b...>>
        {
            using type = list<a..., b...>;
        };

        template<typename head, typename... tail>
        struct _join
        {};

#if !defined(METAL_COMPAT_MODE)
        template<
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p,
            typename head, typename... tail
        >
        struct _join<
            a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p,
            list<head>, list<tail>...
        > :
            _join_impl<
                join_impl<a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p>,
                list<head, tail...>
            >
        {};
#endif

        template<
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p,
            template<typename...> class... _
        >
        struct _join<
            a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p,
            list<>, _<>...
        > :
            _join_impl<a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p>
        {};

        template<
            typename a, typename b, typename c, typename d,
            typename e, typename f, typename g, typename h,
            typename i, typename j, typename k, typename l,
            typename m, typename n, typename o, typename p, typename... tail
        >
        struct _join<a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, tail...> :
            _join<
                join_impl<a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p>,
                tail...
            >
        {};

        template<typename a, typename b, typename... tail>
        struct _join<a, b, tail...> :
            _join<join_impl<a, b>, tail...>
        {};

        template<typename a, typename b>
        struct _join<a, b> :
            _join_impl<a, b>
        {};

        template<typename a>
        struct _join<a>
        {
            using type = a;
        };
    }
}

#endif
