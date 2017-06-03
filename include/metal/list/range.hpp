// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_RANGE_HPP
#define METAL_LIST_RANGE_HPP

#include "../config.hpp"
#include "../list/size.hpp"
#include "../number/if.hpp"
#include "../number/or.hpp"
#include "../number/not.hpp"
#include "../number/number.hpp"
#include "../number/greater.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename seq, typename beg, typename end>
        struct _range;

        template<typename seq, typename beg, typename end>
        using range = typename detail::_range<seq, beg, end>::type;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Returns a contiguous subsequence of a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \numbers `beg` and `end`
    /// \code
    ///     using result = metal::range<l, beg, end>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; beg{} &le; metal::size<l>{}` and
    /// `metal::number<0>{} &le; end{} &le; metal::size<l>{}`
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[i], ..., l[j], ..., l[m-1]`,
    ///     `beg{} == i` and `end{} == j`, then
    ///     \code
    ///         using result = metal::list<l[i], ..., l[j-1]>;
    ///     \endcode
    ///     otherwise, if `beg{} == j` and `end{} == i`, then
    ///     \code
    ///         using result = metal::list<l[j-1], ..., l[i]>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp range
    ///
    /// ### See Also
    /// \see list, erase, take, drop
    template<typename seq, typename beg, typename end>
    using range = detail::range<
        seq,
        if_<not_<or_<greater<number<0>, beg>, greater<beg, size<seq>>>>, beg>,
        if_<not_<or_<greater<number<0>, end>, greater<end, size<seq>>>>, end>
    >;
}

#include "../list/list.hpp"
#include "../list/rotate.hpp"
#include "../list/reverse.hpp"
#include "../number/sub.hpp"
#include "../number/max.hpp"
#include "../number/min.hpp"

#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... vals>
        struct appender
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
                    appender,
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
                    appender,
                    _09, _08, _07, _06, _05, _04, _03, _02, _01, _00
                >;
        };

        template<>
        struct reverser<1>
        {
            template<typename _00, typename... tail>
            using type = typename reverser<sizeof...(tail)>
                ::template type<tail...>::template type<appender, _00>;
        };

        template<>
        struct reverser<0>
        {
            template<typename...>
            using type = appender<>;
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

        template<typename seq>
        using reverse = typename _reverse<seq>::type;

        template<int_ n>
        struct dropper :
            dropper<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)>
        {};

        template<>
        struct dropper<100>
        {
            template<
                int_ n,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename... tail
            >
            using type = typename dropper<(n - 100)>::template type<
                (n - 100), tail...
            >;
        };

        template<>
        struct dropper<10>
        {
            template<
                int_ n,
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename, typename... tail
            >
            using type = typename dropper<(n - 10)>::template type<
                (n - 10), tail...
            >;
        };

        template<>
        struct dropper<1>
        {
            template<int_ n, typename, typename... tail>
            using type = typename dropper<(n - 1)>::template type<
                (n - 1), tail...
            >;
        };

        template<>
        struct dropper<0>
        {
            template<int_, typename... vals>
            using type = list<vals...>;
        };

        template<typename seq, typename num>
        struct _drop
        {};

        template<typename... vals, int_ n>
        struct _drop<list<vals...>, number<n>>
        {
            using type = typename dropper<n>::template type<n, vals...>;
        };

        template<typename seq, typename num>
        using drop = typename _drop<seq, num>::type;

        template<typename seq, typename num>
        using take = drop<rotate<seq, num>, sub<size<seq>, num>>;

        template<typename seq, typename beg, typename end>
        struct _range
        {
            using b = min<beg, end>;
            using e = max<beg, end>;

            using type = range<
                range<range<seq, number<0>, e>, b, e>,
                sub<beg, b>,
                sub<end, b>
            >;
        };

        template<typename seq, typename num>
        struct _range<seq, number<0>, num>
        {
            using type = take<seq, num>;
        };

        template<typename seq, typename num>
        struct _range<seq, num, size<seq>>
        {
            using type = drop<seq, num>;
        };

        template<typename seq>
        struct _range<seq, number<0>, size<seq>>
        {
            using type = seq;
        };

        template<typename seq>
        struct _range<seq, size<seq>, number<0>>
        {
            using type = reverse<seq>;
        };

        template<>
        struct _range<list<>, number<0>, number<0>>
        {
            using type = list<>;
        };
    }
    /// \endcond
}

#endif
