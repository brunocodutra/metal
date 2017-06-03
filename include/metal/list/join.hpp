// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<std::size_t n>
        struct joiner;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Concatenates \lists.
    ///
    /// ### Usage
    /// For any \lists `l_0, ..., l_n-1`
    /// \code
    ///     using result = metal::join<l_0, ..., l_n-1>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<l_0[:], ...[:], l_n-1[:]>;
    ///     \endcode
    ///     where `l[:]` stands for the expansion of all elements contained in
    ///     `l`.
    ///
    /// ### Example
    /// \snippet list.cpp join
    ///
    /// ### See Also
    /// \see list, flatten
    template<typename... seqs>
    using join = detail::call<
        detail::joiner<sizeof...(seqs)>::template type,
        seqs...
    >;
}

#include "../list/list.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>, typename = list<>,
            typename = list<>, typename = list<>
        >
        struct _join_impl
        {};

        template<
            typename... _00, typename... _01, typename... _02, typename... _03,
            typename... _04, typename... _05, typename... _06, typename... _07,
            typename... _08, typename... _09, typename... _10, typename... _11,
            typename... _12, typename... _13, typename... _14, typename... _15,
            typename... _16, typename... _17, typename... _18, typename... _19,
            typename... _20, typename... _21, typename... _22, typename... _23,
            typename... _24, typename... _25, typename... _26, typename... _27,
            typename... _28, typename... _29, typename... _30, typename... _31,
            typename... _32, typename... _33, typename... _34, typename... _35,
            typename... _36, typename... _37, typename... _38, typename... _39,
            typename... _40, typename... _41, typename... _42, typename... _43,
            typename... _44, typename... _45, typename... _46, typename... _47,
            typename... _48, typename... _49, typename... _50, typename... _51,
            typename... _52, typename... _53, typename... _54, typename... _55,
            typename... _56, typename... _57, typename... _58, typename... _59,
            typename... _60, typename... _61, typename... _62, typename... _63,
            typename... _64, typename... _65, typename... _66, typename... _67,
            typename... _68, typename... _69, typename... _70, typename... _71,
            typename... _72, typename... _73, typename... _74, typename... _75,
            typename... _76, typename... _77, typename... _78, typename... _79,
            typename... _80, typename... _81, typename... _82, typename... _83,
            typename... _84, typename... _85, typename... _86, typename... _87,
            typename... _88, typename... _89, typename... _90, typename... _91,
            typename... _92, typename... _93, typename... _94, typename... _95,
            typename... _96, typename... _97, typename... _98, typename... _99,
            typename... _
        >
        struct _join_impl<
            list<_00...>, list<_01...>, list<_02...>, list<_03...>,
            list<_04...>, list<_05...>, list<_06...>, list<_07...>,
            list<_08...>, list<_09...>, list<_10...>, list<_11...>,
            list<_12...>, list<_13...>, list<_14...>, list<_15...>,
            list<_16...>, list<_17...>, list<_18...>, list<_19...>,
            list<_20...>, list<_21...>, list<_22...>, list<_23...>,
            list<_24...>, list<_25...>, list<_26...>, list<_27...>,
            list<_28...>, list<_29...>, list<_30...>, list<_31...>,
            list<_32...>, list<_33...>, list<_34...>, list<_35...>,
            list<_36...>, list<_37...>, list<_38...>, list<_39...>,
            list<_40...>, list<_41...>, list<_42...>, list<_43...>,
            list<_44...>, list<_45...>, list<_46...>, list<_47...>,
            list<_48...>, list<_49...>, list<_50...>, list<_51...>,
            list<_52...>, list<_53...>, list<_54...>, list<_55...>,
            list<_56...>, list<_57...>, list<_58...>, list<_59...>,
            list<_60...>, list<_61...>, list<_62...>, list<_63...>,
            list<_64...>, list<_65...>, list<_66...>, list<_67...>,
            list<_68...>, list<_69...>, list<_70...>, list<_71...>,
            list<_72...>, list<_73...>, list<_74...>, list<_75...>,
            list<_76...>, list<_77...>, list<_78...>, list<_79...>,
            list<_80...>, list<_81...>, list<_82...>, list<_83...>,
            list<_84...>, list<_85...>, list<_86...>, list<_87...>,
            list<_88...>, list<_89...>, list<_90...>, list<_91...>,
            list<_92...>, list<_93...>, list<_94...>, list<_95...>,
            list<_96...>, list<_97...>, list<_98...>, list<_99...>, list<_...>
        >
        {
            using type = list<
                _00..., _01..., _02..., _03..., _04..., _05..., _06..., _07...,
                _08..., _09..., _10..., _11..., _12..., _13..., _14..., _15...,
                _16..., _17..., _18..., _19..., _20..., _21..., _22..., _23...,
                _24..., _25..., _26..., _27..., _28..., _29..., _30..., _31...,
                _32..., _33..., _34..., _35..., _36..., _37..., _38..., _39...,
                _40..., _41..., _42..., _43..., _44..., _45..., _46..., _47...,
                _48..., _49..., _50..., _51..., _52..., _53..., _54..., _55...,
                _56..., _57..., _58..., _59..., _60..., _61..., _62..., _63...,
                _64..., _65..., _66..., _67..., _68..., _69..., _70..., _71...,
                _72..., _73..., _74..., _75..., _76..., _77..., _78..., _79...,
                _80..., _81..., _82..., _83..., _84..., _85..., _86..., _87...,
                _88..., _89..., _90..., _91..., _92..., _93..., _94..., _95...,
                _96..., _97..., _98..., _99..., _...
            >;
        };

        template<typename... seqs>
        using join_impl = typename _join_impl<seqs...>::type;

        template<std::size_t n>
        struct joiner :
            joiner<(n > 100) ? 100 : 0>
        {};

        template<>
        struct joiner<100>
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
            using type = join_impl<
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
                typename joiner<sizeof...(tail)>::template type<tail...>
            >;
        };

        template<>
        struct joiner<0>
        {
            template<typename... seqs>
            using type = join_impl<seqs...>;
        };
    }
    /// \endcond
}

#endif
