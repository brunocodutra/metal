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
#include <metal/number/if.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _join_impl
        {};

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

        template<typename... a, typename... b, typename... c, typename... tail>
        struct _join_impl<list<a...>, list<b...>, list<c...>, tail...> :
            _join<list<a..., b..., c...>, tail...>
        {};

        template<typename... a, typename... b, typename... c>
        struct _join_impl<list<a...>, list<b...>, list<c...>>
        {
            using type = list<a..., b..., c...>;
        };

        template<typename... a, typename... b>
        struct _join_impl<list<a...>, list<b...>>
        {
            using type = list<a..., b...>;
        };

        template<typename... a>
        struct _join<list<a...>>
        {
            using type = list<a...>;
        };

        template<typename head, typename... tail>
        struct _join :
            _join_impl<head, tail...>
        {};

#if !defined(_MSC_VER)
        template<typename... vals, typename head, typename... tail>
        struct _join<list<vals...>, list<head>, list<tail>...>
        {
            using type = list<vals..., head, tail...>;
        };
#endif

        template<typename... vals, template<typename...> class... seq>
        struct _join<list<vals...>, list<>, seq<>...> :
            _if_<same<list<>, seq<>...>, list<vals...>>
        {};
    }
}

#endif
