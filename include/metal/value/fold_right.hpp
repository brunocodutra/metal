// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_FOLD_RIGHT_HPP
#define METAL_VALUE_FOLD_RIGHT_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename lbd>
        struct _fold_right;
    }
    /// \endcond

    /// \ingroup value
    ///
    /// ### Description
    /// Computes the recursive invocation of a binary \lambda with the result of
    /// the previous invocation and each \value, from the last to the first.
    ///
    /// ### Usage
    /// For any \lambda `lbd`, and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::fold_right<lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result =
    ///             lbd(val_0, ..., lbd(val_n-3, lbd(val_n-2, val_n-1)), ...)
    ///     \endcode
    ///     where `lbd(x, y)` stands for `metal::invoke<lbd, x, y>`.
    ///
    /// ### Example
    /// \snippet value.cpp fold_right
    ///
    /// ### See Also
    /// \see fold_right
    template<typename lbd, typename... vals>
    using fold_right =
        detail::call<detail::_fold_right<lbd>::template type, vals...>;
}

#include "../lambda/lambda.hpp"
#include "../value/identity.hpp"

#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<
            typename state,
            /* clang-format off */
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
            typename _96, typename _97, typename _98, typename _99
            /* clang-format on */
            >
        struct right_folder_100 {
            template<template<typename...> class expr>
            using type =
                /* clang-format off */
                expr<_00, expr<_01, expr<_02, expr<_03, expr<_04,
                expr<_05, expr<_06, expr<_07, expr<_08, expr<_09,
                expr<_10, expr<_11, expr<_12, expr<_13, expr<_14,
                expr<_15, expr<_16, expr<_17, expr<_18, expr<_19,
                expr<_20, expr<_21, expr<_22, expr<_23, expr<_24,
                expr<_25, expr<_26, expr<_27, expr<_28, expr<_29,
                expr<_30, expr<_31, expr<_32, expr<_33, expr<_34,
                expr<_35, expr<_36, expr<_37, expr<_38, expr<_39,
                expr<_40, expr<_41, expr<_42, expr<_43, expr<_44,
                expr<_45, expr<_46, expr<_47, expr<_48, expr<_49,
                expr<_50, expr<_51, expr<_52, expr<_53, expr<_54,
                expr<_55, expr<_56, expr<_57, expr<_58, expr<_59,
                expr<_60, expr<_61, expr<_62, expr<_63, expr<_64,
                expr<_65, expr<_66, expr<_67, expr<_68, expr<_69,
                expr<_70, expr<_71, expr<_72, expr<_73, expr<_74,
                expr<_75, expr<_76, expr<_77, expr<_78, expr<_79,
                expr<_80, expr<_81, expr<_82, expr<_83, expr<_84,
                expr<_85, expr<_86, expr<_87, expr<_88, expr<_89,
                expr<_90, expr<_91, expr<_92, expr<_93, expr<_94,
                expr<_95, expr<_96, expr<_97, expr<_98, expr<_99,
                    forward<state::template type, expr>
                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                /* clang-format on */
                ;
        };

        template<
            typename state,
            /* clang-format off */
            typename _00, typename _01, typename _02, typename _03,
            typename _04, typename _05, typename _06, typename _07,
            typename _08, typename _09
            /* clang-format on */
            >
        struct right_folder_10 {
            template<template<typename...> class expr>
            using type =
                /* clang-format off */
                expr<_00, expr<_01, expr<_02, expr<_03, expr<_04,
                expr<_05, expr<_06, expr<_07, expr<_08, expr<_09,
                    forward<state::template type, expr>
                >>>>>>>>>>
                /* clang-format on */
                ;
        };

        template<typename state, typename _00>
        struct right_folder_1 {
            template<template<typename...> class expr>
            using type = expr<_00, forward<state::template type, expr>>;
        };

        template<typename state>
        struct right_folder_0 {
            template<template<typename...> class>
            using type = identity<state>;
        };

        template<std::size_t n>
        struct _fold_right_impl
            : _fold_right_impl<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {};

        template<>
        struct _fold_right_impl<100> {
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
                typename... tail>
            using type = right_folder_100<
                typename _fold_right_impl<sizeof...(tail) - 1>::template type<
                    tail...>,
                /* clang-format off */
                _00, _01, _02, _03, _04, _05, _06, _07, _08, _09,
                _10, _11, _12, _13, _14, _15, _16, _17, _18, _19,
                _20, _21, _22, _23, _24, _25, _26, _27, _28, _29,
                _30, _31, _32, _33, _34, _35, _36, _37, _38, _39,
                _40, _41, _42, _43, _44, _45, _46, _47, _48, _49,
                _50, _51, _52, _53, _54, _55, _56, _57, _58, _59,
                _60, _61, _62, _63, _64, _65, _66, _67, _68, _69,
                _70, _71, _72, _73, _74, _75, _76, _77, _78, _79,
                _80, _81, _82, _83, _84, _85, _86, _87, _88, _89,
                _90, _91, _92, _93, _94, _95, _96, _97, _98, _99
                /* clang-format on */
                >;
        };

        template<>
        struct _fold_right_impl<10> {
            template<
                typename _00, typename _01, typename _02, typename _03,
                typename _04, typename _05, typename _06, typename _07,
                typename _08, typename _09, typename... tail>
            using type = right_folder_10<
                typename _fold_right_impl<sizeof...(tail) - 1>::template type<
                    tail...>,
                _00, _01, _02, _03, _04, _05, _06, _07, _08, _09>;
        };

        template<>
        struct _fold_right_impl<1> {
            template<typename _00, typename... tail>
            using type = right_folder_1<
                typename _fold_right_impl<sizeof...(tail) - 1>::template type<
                    tail...>,
                _00>;
        };

        template<>
        struct _fold_right_impl<0> {
            template<typename _00>
            using type = right_folder_0<_00>;
        };

        template<typename state, typename... vals>
        struct right_folder
            : _fold_right_impl<sizeof...(vals)>::template type<state, vals...> {
        };

        template<typename lbd>
        struct _fold_right {};

        template<template<typename...> class expr>
        struct _fold_right<lambda<expr>> {
            template<typename... vals>
            using type = forward<right_folder<vals...>::template type, expr>;
        };
    }
    /// \endcond
}

#endif
