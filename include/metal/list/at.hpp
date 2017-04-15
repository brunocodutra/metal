// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP

#include <metal/config.hpp>

#include <metal/detail/sfinae.hpp>

namespace metal {
    /// \cond
    namespace detail {
        template<typename seq>
        struct _at;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Retrieves an element of a \list at an arbitrary position.
    ///
    /// ### Usage
    /// For any \list `l` and \number `num`
    /// \code
    ///     using result = metal::at<l, num>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; num{} < metal::size<l>{}`
    /// \returns: \value
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
    ///     `num{} == i`, then
    ///     \code
    ///         using result = l[i];
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp at
    ///
    /// ### See Also
    /// \see list, front, back
    template<typename seq, typename num>
    using at = detail::call<detail::_at<seq>::template type, num>;
}

#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#if defined(__has_builtin)
#   if __has_builtin(__type_pack_element)
#       define METAL_USE_BUILTIN_TYPE_PACK_ELEMENT
#   endif
#endif

namespace metal {
    /// \cond
    namespace detail {
        template<typename... vals>
        struct grouper_impl
        {
            template<template<typename...> class expr, typename... _>
            using type = expr<_..., vals...>;
        };

        template<std::size_t n>
        struct grouper :
            grouper<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)>
        {};

        template<>
        struct grouper<100>
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
            using type = typename grouper<sizeof...(tail)>
                ::template type<tail...>::template type<
                    grouper_impl,
                    _at<list<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09>>,
                    _at<list<_10, _11, _12, _13, _14, _15, _16, _17, _18, _19>>,
                    _at<list<_20, _21, _22, _23, _24, _25, _26, _27, _28, _29>>,
                    _at<list<_30, _31, _32, _33, _34, _35, _36, _37, _38, _39>>,
                    _at<list<_40, _41, _42, _43, _44, _45, _46, _47, _48, _49>>,
                    _at<list<_50, _51, _52, _53, _54, _55, _56, _57, _58, _59>>,
                    _at<list<_60, _61, _62, _63, _64, _65, _66, _67, _68, _69>>,
                    _at<list<_70, _71, _72, _73, _74, _75, _76, _77, _78, _79>>,
                    _at<list<_80, _81, _82, _83, _84, _85, _86, _87, _88, _89>>,
                    _at<list<_90, _91, _92, _93, _94, _95, _96, _97, _98, _99>>
                >;
        };

        template<>
        struct grouper<10>
        {
            template<
                typename _00, typename _01, typename _02, typename _03,
                typename _04, typename _05, typename _06, typename _07,
                typename _08, typename _09, typename... tail
            >
            using type = typename grouper<sizeof...(tail)>
                ::template type<tail...>::template type<
                    grouper_impl,
                    _at<list<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09>>
                >;
        };

        template<>
        struct grouper<1>
        {
            template<typename... vals>
            using type = grouper_impl<_at<list<vals...>>>;
        };

        template<>
        struct grouper<0>
        {
            template<typename...>
            using type = grouper_impl<>;
        };

        template<typename num, typename = true_>
        struct _at_impl
        {};

        template<int_ n>
        struct _at_impl<number<n>, number<(n > 9)>>
        {
            template<typename... vals>
            using type = typename grouper<sizeof...(vals)>
                ::template type<vals...>
                    ::template type<_at_impl<number<n/10>>::template type>
                        ::template type<number<n%10>>;
        };

        template<>
        struct _at_impl<number<9>>
        {
            template<
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename, typename val, typename...
            >
            using type = val;
        };

        template<>
        struct _at_impl<number<8>>
        {
            template<
                typename, typename, typename, typename, typename, typename,
                typename, typename, typename val, typename...
            >
            using type = val;
        };

        template<>
        struct _at_impl<number<7>>
        {
            template<
                typename, typename, typename, typename, typename, typename,
                typename, typename val, typename...
            >
            using type = val;
        };

        template<>
        struct _at_impl<number<6>>
        {
            template<
                typename, typename, typename, typename, typename, typename,
                typename val, typename...
            >
            using type = val;
        };

        template<>
        struct _at_impl<number<5>>
        {
            template<
                typename, typename, typename, typename, typename, typename val,
                typename...
            >
            using type = val;
        };

        template<>
        struct _at_impl<number<4>>
        {
            template<
                typename, typename, typename, typename, typename val,
                typename...
            >
            using type = val;
        };

        template<>
        struct _at_impl<number<3>>
        {
            template<typename, typename, typename, typename val, typename...>
            using type = val;
        };

        template<>
        struct _at_impl<number<2>>
        {
            template<typename, typename, typename val, typename...>
            using type = val;
        };

        template<>
        struct _at_impl<number<1>>
        {
            template<typename, typename val, typename...>
            using type = val;
        };

        template<>
        struct _at_impl<number<0>>
        {
            template<typename val, typename...>
            using type = val;
        };

        template<typename seq>
        struct _at
        {};

        template<typename... vals>
        struct _at<list<vals...>>
        {
#if defined(METAL_USE_BUILTIN_TYPE_PACK_ELEMENT)
            template<typename, typename = true_>
            struct impl
            {};

            template<int_ n>
            struct impl<number<n>, number<(n >= 0 && n < sizeof...(vals))>>
            {
                using type = __type_pack_element<n, vals...>;
            };

            template<typename num>
            using type = typename impl<num>::type;
#else
            template<typename num>
            using type = call<_at_impl<num>::template type, vals...>;
#endif
        };
    }
    /// \endcond
}

#endif
