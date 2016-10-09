// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FOLD_LEFT_HPP
#define METAL_LIST_FOLD_LEFT_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename seq, typename state, typename lbd>
        struct _fold_left;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename state, typename lbd>
    using fold_left = typename detail::_fold_left<seq, state, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename cons, typename state, typename lbd, typename = true_>
        struct _fold_left_impl
        {};

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
            typename tail,
            typename state, template<typename...> class expr
        >
        struct _fold_left_impl<
            list<
                _00, _01, _02, _03, _04, _05, _06, _07, _08, _09,
                _10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
                _20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
                _30, _31, _32, _33, _34, _35, _36, _37, _38, _39,
                _40, _41, _42, _43, _44, _45, _46, _47, _48, _49,
                _50, _51, _52, _53, _54, _55, _56, _57, _58, _59,
                _60, _61, _62, _63, _64, _65, _66, _67, _68, _69,
                _70, _71, _72, _73, _74, _75, _76, _77, _78, _79,
                _80, _81, _82, _83, _84, _85, _86, _87, _88, _89,
                _90, _91, _92, _93, _94, _95, _96, _97, _98, _99, tail
            >,
            state,
            lambda<expr>,
            is_value<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<state,
                    _00>, _01>, _02>, _03>, _04>, _05>, _06>, _07>, _08>, _09>,
                    _10>, _11>, _12>, _13>, _14>, _15>, _16>, _17>, _18>, _19>,
                    _20>, _21>, _22>, _23>, _24>, _25>, _26>, _27>, _28>, _29>,
                    _30>, _31>, _32>, _33>, _34>, _35>, _36>, _37>, _38>, _39>,
                    _40>, _41>, _42>, _43>, _44>, _45>, _46>, _47>, _48>, _49>,
                    _50>, _51>, _52>, _53>, _54>, _55>, _56>, _57>, _58>, _59>,
                    _60>, _61>, _62>, _63>, _64>, _65>, _66>, _67>, _68>, _69>,
                    _70>, _71>, _72>, _73>, _74>, _75>, _76>, _77>, _78>, _79>,
                    _80>, _81>, _82>, _83>, _84>, _85>, _86>, _87>, _88>, _89>,
                    _90>, _91>, _92>, _93>, _94>, _95>, _96>, _97>, _98>, _99>
            >
        > :
            _fold_left_impl<
                tail,
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<state,
                    _00>, _01>, _02>, _03>, _04>, _05>, _06>, _07>, _08>, _09>,
                    _10>, _11>, _12>, _13>, _14>, _15>, _16>, _17>, _18>, _19>,
                    _20>, _21>, _22>, _23>, _24>, _25>, _26>, _27>, _28>, _29>,
                    _30>, _31>, _32>, _33>, _34>, _35>, _36>, _37>, _38>, _39>,
                    _40>, _41>, _42>, _43>, _44>, _45>, _46>, _47>, _48>, _49>,
                    _50>, _51>, _52>, _53>, _54>, _55>, _56>, _57>, _58>, _59>,
                    _60>, _61>, _62>, _63>, _64>, _65>, _66>, _67>, _68>, _69>,
                    _70>, _71>, _72>, _73>, _74>, _75>, _76>, _77>, _78>, _79>,
                    _80>, _81>, _82>, _83>, _84>, _85>, _86>, _87>, _88>, _89>,
                    _90>, _91>, _92>, _93>, _94>, _95>, _96>, _97>, _98>, _99>,
                lambda<expr>
            >
        {};

        template<
            typename _00, typename _01, typename _02, typename _03,
            typename _04, typename _05, typename _06, typename _07,
            typename _08, typename _09, typename tail,
            typename state, template<typename...> class expr
        >
        struct _fold_left_impl<
            list<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09, tail>,
            state,
            lambda<expr>,
            is_value<
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<state,
                    _00>, _01>, _02>, _03>, _04>, _05>, _06>, _07>, _08>, _09>
            >
        > :
            _fold_left_impl<
                tail,
                expr<expr<expr<expr<expr<expr<expr<expr<expr<expr<state,
                    _00>, _01>, _02>, _03>, _04>, _05>, _06>, _07>, _08>, _09>,
                lambda<expr>
            >
        {};

        template<
            typename head, typename tail,
            typename state, template<typename...> class expr
        >
        struct _fold_left_impl<list<head, tail>, state, lambda<expr>,
            is_value<expr<state, head>>
        > :
            _fold_left_impl<tail, expr<state, head>, lambda<expr>>
        {};

        template<typename state, template<typename...> class expr>
        struct _fold_left_impl<list<>, state, lambda<expr>>
        {
            using type = state;
        };

        template<int_ n>
        struct _cons_impl :
            _cons_impl<(n >= 100) ? 100 : (n >= 10) ? 10 : (n >= 1)>
        {};

        template<>
        struct _cons_impl<100>
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
            using type = list<
                _00, _01, _02, _03, _04, _05, _06, _07, _08, _09,
                _10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
                _20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
                _30, _31, _32, _33, _34, _35, _36, _37, _38, _39,
                _40, _41, _42, _43, _44, _45, _46, _47, _48, _49,
                _50, _51, _52, _53, _54, _55, _56, _57, _58, _59,
                _60, _61, _62, _63, _64, _65, _66, _67, _68, _69,
                _70, _71, _72, _73, _74, _75, _76, _77, _78, _79,
                _80, _81, _82, _83, _84, _85, _86, _87, _88, _89,
                _90, _91, _92, _93, _94, _95, _96, _97, _98, _99,
                typename _cons_impl<sizeof...(tail)>::template type<tail...>
            >;
        };

        template<>
        struct _cons_impl<10>
        {
            template<
                typename _00, typename _01, typename _02, typename _03,
                typename _04, typename _05, typename _06, typename _07,
                typename _08, typename _09, typename... tail
            >
            using type = list<
                _00, _01, _02, _03, _04, _05, _06, _07, _08, _09,
                typename _cons_impl<sizeof...(tail)>::template type<tail...>
            >;
        };

        template<>
        struct _cons_impl<1>
        {
            template<typename head, typename... tail>
            using type = list<
                head,
                typename _cons_impl<sizeof...(tail)>::template type<tail...>
            >;
        };

        template<>
        struct _cons_impl<0>
        {
            template<typename...>
            using type = list<>;
        };

        template<typename... vals>
        struct _cons
        {
            using type =
                typename _cons_impl<sizeof...(vals)>::template type<vals...>;
        };

        template<typename... vals>
        using cons = typename _cons<vals...>::type;

        template<typename seq, typename state, typename lbd>
        struct _fold_left
        {};

        template<typename... vals, typename state, typename lbd>
        struct _fold_left<list<vals...>, state, lbd> :
            _fold_left_impl<cons<vals...>, state, lbd>
        {};
    }
    /// \endcond
}

#endif
