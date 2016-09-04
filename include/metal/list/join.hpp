// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

#include <metal/config.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... seqs>
        struct _join;
    }

    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename head, typename... tail>
    using join = typename detail::_join<head, tail...>::type;
}

#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename, typename, typename, typename, typename,
            typename, typename, typename, typename, typename
        >
        struct _join10
        {};

        template<
            typename... _0, typename... _1, typename... _2, typename... _3,
            typename... _4, typename... _5, typename... _6, typename... _7,
            typename... _8, typename... _9
        >
        struct _join10<
            list<_0...>, list<_1...>, list<_2...>, list<_3...>,
            list<_4...>, list<_5...>, list<_6...>, list<_7...>,
            list<_8...>, list<_9...>
        >
        {
            using type = list<
                _0..., _1..., _2..., _3..., _4...,
                _5..., _6..., _7..., _8..., _9...

            >;
        };

        template<typename, typename, typename>
        struct _join3
        {};

        template<typename... _0, typename... _1, typename... _2>
        struct _join3<list<_0...>, list<_1...>, list<_2...>>
        {
            using type = list<_0..., _1..., _2...>;
        };

        template<typename, typename>
        struct _join2
        {};

        template<typename... _0, typename... _1>
        struct _join2<list<_0...>, list<_1...>>
        {
            using type = list<_0..., _1...>;
        };

        template<int_ n>
        struct _join_impl :
            _join_impl<(n >= 100) ? 100 : (n >= 10) ? 10 : (n >= 1)>
        {};

        template<>
        struct _join_impl<100>
        {
            template<
                typename _00, typename _01, typename _02, typename _03,
                typename _04, typename _05, typename _06, typename _07,
                typename _08, typename _09, typename _10, typename _11,
                typename _12, typename _13, typename _14, typename _15,
                typename _16, typename _17, typename _18, typename _19,
                typename _20, typename _21, typename _22, typename _23,
                typename _24, typename _25, typename _26, typename _27,
                typename _28, typename _29, typename _30, typename _31,
                typename _32, typename _33, typename _34, typename _35,
                typename _36, typename _37, typename _38, typename _39,
                typename _40, typename _41, typename _42, typename _43,
                typename _44, typename _45, typename _46, typename _47,
                typename _48, typename _49, typename _50, typename _51,
                typename _52, typename _53, typename _54, typename _55,
                typename _56, typename _57, typename _58, typename _59,
                typename _60, typename _61, typename _62, typename _63,
                typename _64, typename _65, typename _66, typename _67,
                typename _68, typename _69, typename _70, typename _71,
                typename _72, typename _73, typename _74, typename _75,
                typename _76, typename _77, typename _78, typename _79,
                typename _80, typename _81, typename _82, typename _83,
                typename _84, typename _85, typename _86, typename _87,
                typename _88, typename _89, typename _90, typename _91,
                typename _92, typename _93, typename _94, typename _95,
                typename _96, typename _97, typename _98, typename _99,
                typename... tail
            >
            using type = join<
                join<
                    join<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09>,
                    join<_10, _11, _12, _13, _14, _15, _16, _17, _18, _19>,
                    join<_20, _21, _22, _23, _24, _25, _26, _27, _28, _29>,
                    join<_30, _31, _32, _33, _34, _35, _36, _37, _38, _39>,
                    join<_40, _41, _42, _43, _44, _45, _46, _47, _48, _49>,
                    join<_50, _51, _52, _53, _54, _55, _56, _57, _58, _59>,
                    join<_60, _61, _62, _63, _64, _65, _66, _67, _68, _69>,
                    join<_70, _71, _72, _73, _74, _75, _76, _77, _78, _79>,
                    join<_80, _81, _82, _83, _84, _85, _86, _87, _88, _89>,
                    join<_90, _91, _92, _93, _94, _95, _96, _97, _98, _99>
                >,
                typename _join_impl<sizeof...(tail)>::template type<tail...>
            >;
        };

        template<>
        struct _join_impl<10>
        {
            template<
                typename _00, typename _01, typename _02, typename _03,
                typename _04, typename _05, typename _06, typename _07,
                typename _08, typename _09, typename... tail
            >
            using type = join<
                join<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09>,
                typename _join_impl<sizeof...(tail)>::template type<tail...>
            >;
        };

        template<>
        struct _join_impl<1>
        {
            template<typename head, typename... tail>
            using type = join<
                head,
                typename _join_impl<sizeof...(tail)>::template type<tail...>
            >;
        };

        template<>
        struct _join_impl<0>
        {
            template<typename...>
            using type = list<>;
        };

        template<typename... seqs>
        struct _join :
            _invoke<lambda<_join_impl<sizeof...(seqs)>::template type>, seqs...>
        {};

        template<
            typename _00, typename _01, typename _02, typename _03,
            typename _04, typename _05, typename _06, typename _07,
            typename _08, typename _09
        >
        struct _join<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09> :
            _join10<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09>
        {};

        template<typename _00, typename _01, typename _02>
        struct _join<_00, _01, _02> :
            _join3<_00, _01, _02>
        {};

        template<typename _00, typename _01>
        struct _join<_00, _01> :
            _join2<_00, _01>
        {};

        template<typename seq>
        struct _join<seq> :
            _if_<is_list<seq>, seq>
        {};
    }
}

#endif
