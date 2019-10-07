#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class seq>
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
    template<class seq, class num>
    using at = detail::call<detail::_at<seq>::template type, num>;
}

#include "../list/list.hpp"
#include "../number/number.hpp"

#if defined(__has_builtin)
#if __has_builtin(__type_pack_element)
#define METAL_USE_BUILTIN_TYPE_PACK_ELEMENT
#endif
#endif

namespace metal {
    /// \cond
    namespace detail {
        template<class... vals>
        struct prepender {
            template<class... _>
            using prepend = prepender<_..., vals...>;

            using type = list<vals...>;
        };

        template<std::size_t n>
        struct grouper : grouper<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {};

        template<>
        struct grouper<100> {
            template<
                class _00, class _01, class _02, class _03, class _04,
                class _05, class _06, class _07, class _08, class _09,
                class _10, class _11, class _12, class _13, class _14,
                class _15, class _16, class _17, class _18, class _19,
                class _20, class _21, class _22, class _23, class _24,
                class _25, class _26, class _27, class _28, class _29,
                class _30, class _31, class _32, class _33, class _34,
                class _35, class _36, class _37, class _38, class _39,
                class _40, class _41, class _42, class _43, class _44,
                class _45, class _46, class _47, class _48, class _49,
                class _50, class _51, class _52, class _53, class _54,
                class _55, class _56, class _57, class _58, class _59,
                class _60, class _61, class _62, class _63, class _64,
                class _65, class _66, class _67, class _68, class _69,
                class _70, class _71, class _72, class _73, class _74,
                class _75, class _76, class _77, class _78, class _79,
                class _80, class _81, class _82, class _83, class _84,
                class _85, class _86, class _87, class _88, class _89,
                class _90, class _91, class _92, class _93, class _94,
                class _95, class _96, class _97, class _98, class _99,
                class... tail>
            using type = typename grouper<sizeof...(tail)>::
                template type<tail...>::template prepend<
                    /* clang-format off */
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
                    /* clang-format on */
                    >;
        };

        template<>
        struct grouper<10> {
            template<
                class _00, class _01, class _02, class _03, class _04,
                class _05, class _06, class _07, class _08, class _09,
                class... tail>
            using type = typename grouper<sizeof...(tail)>::
                template type<tail...>::template prepend<_at<
                    list<_00, _01, _02, _03, _04, _05, _06, _07, _08, _09>>>;
        };

        template<>
        struct grouper<1> {
            template<class... vals>
            using type = prepender<_at<list<vals...>>>;
        };

        template<>
        struct grouper<0> {
            template<class...>
            using type = prepender<>;
        };

        template<class... vals>
        using group =
            typename grouper<sizeof...(vals)>::template type<vals...>::type;

        template<class groups, class m, class n>
        using select = typename _at<groups>::template type<m>::template type<n>;

        template<class num, class = true_>
        struct _at_impl {};

        template<int_ n>
        struct _at_impl<number<n>, number<(n > 9)>> {
            template<class... vals>
            using type =
                select<call<group, vals...>, number<n / 10>, number<n % 10>>;
        };

        template<>
        struct _at_impl<number<9>> {
            template<
                class, class, class, class, class, class, class, class, class,
                class val, class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<8>> {
            template<
                class, class, class, class, class, class, class, class,
                class val, class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<7>> {
            template<
                class, class, class, class, class, class, class, class val,
                class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<6>> {
            template<
                class, class, class, class, class, class, class val, class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<5>> {
            template<class, class, class, class, class, class val, class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<4>> {
            template<class, class, class, class, class val, class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<3>> {
            template<class, class, class, class val, class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<2>> {
            template<class, class, class val, class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<1>> {
            template<class, class val, class...>
            using type = val;
        };

        template<>
        struct _at_impl<number<0>> {
            template<class val, class...>
            using type = val;
        };

        template<class seq>
        struct _at {};

        template<class... vals>
        struct _at<list<vals...>> {
#if defined(METAL_USE_BUILTIN_TYPE_PACK_ELEMENT)
            template<class, class = true_>
            struct impl {};

            template<int_ n>
            struct impl<number<n>, number<(n >= 0 && n < sizeof...(vals))>> {
                using type = __type_pack_element<n, vals...>;
            };

            template<class... num>
            using type = typename impl<num...>::type;
#else
            template<class... num>
            using type = call<_at_impl<num...>::template type, vals...>;
#endif
        };
    }
    /// \endcond
}

#endif
