// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REVERSE_HPP
#define METAL_LIST_REVERSE_HPP

#include <metal/config.hpp>

namespace metal {
    /// \cond
    namespace detail {
        template<typename seq>
        struct _reverse;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Reverses the order of the elements of a \list.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::reverse<l>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::list<l[m-1], ..., l[0]>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp reverse
    ///
    /// ### See Also
    /// \see list, rotate, sort
    template<typename seq>
    using reverse = typename detail::_reverse<seq>::type;
}

#include <metal/list/list.hpp>

#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... vals>
        struct reverser_impl
        {
            template<template<typename...> class expr, typename... _>
            using type = expr<vals..., _...>;
        };

        template<std::size_t n>
        struct reverser :
            reverser<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)>
        {};

        template<>
        struct reverser<100>
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
            using type = typename reverser<sizeof...(tail)>
                ::template type<tail...>::template type<
                    reverser_impl,
                    _99, _98, _97, _96, _95, _94, _93, _92, _91, _90,
                    _89, _88, _87, _86, _85, _84, _83, _82, _81, _80,
                    _79, _78, _77, _76, _75, _74, _73, _72, _71, _70,
                    _69, _68, _67, _66, _65, _64, _63, _62, _61, _60,
                    _59, _58, _57, _56, _55, _54, _53, _52, _51, _50,
                    _49, _48, _47, _46, _45, _44, _43, _42, _41, _40,
                    _39, _38, _37, _36, _35, _34, _33, _32, _31, _30,
                    _29, _28, _27, _26, _25, _24, _23, _22, _21, _20,
                    _19, _18, _17, _16, _15, _14, _13, _12, _11, _10,
                    _09, _08, _07, _06, _05, _04, _03, _02, _01, _00
                >;
        };

        template<>
        struct reverser<10>
        {
            template<
                typename _00, typename _01, typename _02, typename _03,
                typename _04, typename _05, typename _06, typename _07,
                typename _08, typename _09, typename... tail
            >
            using type = typename reverser<sizeof...(tail)>
                ::template type<tail...>::template type<
                    reverser_impl,
                    _09, _08, _07, _06, _05, _04, _03, _02, _01, _00
                >;
        };

        template<>
        struct reverser<1>
        {
            template<typename _00, typename... tail>
            using type = typename reverser<sizeof...(tail)>
                ::template type<tail...>::template type<reverser_impl, _00>;
        };

        template<>
        struct reverser<0>
        {
            template<typename...>
            using type = reverser_impl<>;
        };

        template<typename seq>
        struct _reverse
        {};

        template<typename... vals>
        struct _reverse<list<vals...>>
        {
            using type = typename reverser<sizeof...(vals)>
                ::template type<vals...>::template type<list>;
        };
    }
    /// \endcond
}

#endif
