#ifndef METAL_LIST_RANGE_HPP
#define METAL_LIST_RANGE_HPP

#include "../config.hpp"
#include "../list/size.hpp"
#include "../number/greater.hpp"
#include "../number/if.hpp"
#include "../number/not.hpp"
#include "../number/number.hpp"
#include "../number/or.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class seq, class beg, class end>
        struct _range;

        template<class seq, class beg, class end>
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
    template<class seq, class beg, class end>
    using range = detail::range<
        seq,
        if_<not_<or_<greater<number<0>, beg>, greater<beg, size<seq>>>>, beg>,
        if_<not_<or_<greater<number<0>, end>, greater<end, size<seq>>>>, end>>;
}

#include "../list/list.hpp"
#include "../list/reverse.hpp"
#include "../list/rotate.hpp"
#include "../number/max.hpp"
#include "../number/min.hpp"
#include "../number/sub.hpp"

#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<class... vals>
        struct appender {
            template<class... _>
            using append = appender<vals..., _...>;

            using type = list<vals...>;
        };

        template<std::size_t n>
        struct reverser
            : reverser<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {};

        template<>
        struct reverser<100> {
            template<
                class _00, class _01, class _02, class _03,
                class _04, class _05, class _06, class _07,
                class _08, class _09, class _10, class _11,
                class _12, class _13, class _14, class _15,
                class _16, class _17, class _18, class _19,
                class _20, class _21, class _22, class _23,
                class _24, class _25, class _26, class _27,
                class _28, class _29, class _30, class _31,
                class _32, class _33, class _34, class _35,
                class _36, class _37, class _38, class _39,
                class _40, class _41, class _42, class _43,
                class _44, class _45, class _46, class _47,
                class _48, class _49, class _50, class _51,
                class _52, class _53, class _54, class _55,
                class _56, class _57, class _58, class _59,
                class _60, class _61, class _62, class _63,
                class _64, class _65, class _66, class _67,
                class _68, class _69, class _70, class _71,
                class _72, class _73, class _74, class _75,
                class _76, class _77, class _78, class _79,
                class _80, class _81, class _82, class _83,
                class _84, class _85, class _86, class _87,
                class _88, class _89, class _90, class _91,
                class _92, class _93, class _94, class _95,
                class _96, class _97, class _98, class _99,
                class... tail>
            using type = typename reverser<sizeof...(tail)>::
                template type<tail...>::template append<
                    /* clang-format off */
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
                    /* clang-format on */
                    >;
        };

        template<>
        struct reverser<10> {
            template<
                class _00, class _01, class _02, class _03,
                class _04, class _05, class _06, class _07,
                class _08, class _09, class... tail>
            using type = typename reverser<sizeof...(tail)>::
                template type<tail...>::template append<
                    _09, _08, _07, _06, _05, _04, _03, _02, _01, _00>;
        };

        template<>
        struct reverser<1> {
            template<class _00, class... tail>
            using type = typename reverser<sizeof...(
                tail)>::template type<tail...>::template append<_00>;
        };

        template<>
        struct reverser<0> {
            template<class...>
            using type = appender<>;
        };

        template<class seq>
        struct _reverse {};

        template<class... vals>
        struct _reverse<list<vals...>> {
            using type = typename reverser<sizeof...(
                vals)>::template type<vals...>::type;
        };

        template<class seq>
        using reverse = typename _reverse<seq>::type;

        template<int_ n>
        struct dropper : dropper<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {};

        template<>
        struct dropper<100> {
            template<
                int_ n,
                /* clang-format off */
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class, class,
                class, class, class, class, class... tail
                /* clang-format on */
                >
            using type =
                typename dropper<(n - 100)>::template type<(n - 100), tail...>;
        };

        template<>
        struct dropper<10> {
            template<
                int_ n,
                /* clang-format off */
                class, class, class, class, class, class,
                class, class, class, class, class... tail
                /* clang-format on */
                >
            using type =
                typename dropper<(n - 10)>::template type<(n - 10), tail...>;
        };

        template<>
        struct dropper<1> {
            template<int_ n, class, class... tail>
            using type =
                typename dropper<(n - 1)>::template type<(n - 1), tail...>;
        };

        template<>
        struct dropper<0> {
            template<int_, class... vals>
            using type = list<vals...>;
        };

        template<class seq, class num>
        struct _drop {};

        template<class... vals, int_ n>
        struct _drop<list<vals...>, number<n>> {
            using type = typename dropper<n>::template type<n, vals...>;
        };

        template<class seq, class num>
        using drop = typename _drop<seq, num>::type;

        template<class seq, class num>
        using take = drop<rotate<seq, num>, sub<size<seq>, num>>;

        template<class seq, class beg, class end>
        struct _range {
            using b = min<beg, end>;
            using e = max<beg, end>;

            using type = range<
                range<range<seq, number<0>, e>, b, e>, sub<beg, b>,
                sub<end, b>>;
        };

        template<class seq, class num>
        struct _range<seq, number<0>, num> {
            using type = take<seq, num>;
        };

        template<class seq, class num>
        struct _range<seq, num, size<seq>> {
            using type = drop<seq, num>;
        };

        template<class seq>
        struct _range<seq, number<0>, size<seq>> {
            using type = seq;
        };

        template<class seq>
        struct _range<seq, size<seq>, number<0>> {
            using type = reverse<seq>;
        };

        template<>
        struct _range<list<>, number<0>, number<0>> {
            using type = list<>;
        };
    }
    /// \endcond
}

#endif
