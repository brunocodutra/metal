#ifndef METAL_LIST_SORT_HPP
#define METAL_LIST_SORT_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename lbd>
        struct _sort;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Sorts the elements of a \list according to an ordering relation.
    ///
    /// \tip{The sorting is [stable] if the ordering relation is [strict].}
    /// [stable]: https://en.wikipedia.org/wiki/Sorting_algorithm#Stability
    /// [strict]: https://en.wikipedia.org/wiki/Weak_ordering#Strict_weak_orderings
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::sort<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any two \values `val_i` and `val_j` contained in `l`
    /// `metal::expr<val_i, val_j>` returns a \number
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<val_0, ..., val_m-1>;
    ///     \endcode
    ///     where `val_0, ..., val_m-1` is a permutation of the elements in `l`
    ///     such that `metal::expr<val_i, val_i+1>{} != false` for all
    ///     `i` in `[0, m-2]`.
    ///
    /// ### Example
    /// \snippet list.cpp sort
    ///
    /// ### See Also
    /// \see list, reverse, rotate
    template<typename seq, typename lbd>
    using sort = detail::call<detail::_sort<lbd>::template type, seq>;
}

#include "../lambda/lambda.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../list/range.hpp"
#include "../number/if.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {

        template<typename>
        struct cons {};

        template<typename h, typename... t>
        struct cons<list<h, t...>> {
            using head = h;
            using tail = list<t...>;
        };

        template<typename seq>
        using head = typename cons<seq>::head;

        template<typename seq>
        using tail = typename cons<seq>::tail;

        template<
            typename, typename, typename, template<typename...> class,
            typename = true_>
        struct _partial_merge {};

        template<
            typename x, typename y, typename... zs,
            template<typename...> class e>
        struct _partial_merge<
            x, y, list<zs...>, e, if_<call<e, head<y>, head<x>>, true_, false_>>
            : _partial_merge<x, tail<y>, list<zs..., head<y>>, e> {};

        template<
            typename x, typename y, typename... zs,
            template<typename...> class e>
        struct _partial_merge<
            x, y, list<zs...>, e, if_<call<e, head<y>, head<x>>, false_, true_>>
            : _partial_merge<tail<x>, y, list<zs..., head<x>>, e> {};

        template<typename... xs, typename... zs, template<typename...> class e>
        struct _partial_merge<list<xs...>, list<>, list<zs...>, e> {
            using type = list<zs...>;
            using l1_carry = list<xs...>;
            using l2_carry = list<>;
        };

        template<typename... ys, typename... zs, template<typename...> class e>
        struct _partial_merge<list<>, list<ys...>, list<zs...>, e> {
            using type = list<zs...>;
            using l1_carry = list<>;
            using l2_carry = list<ys...>;
        };

        template<typename z, template<typename...> class e>
        struct _partial_merge<list<>, list<>, z, e> {
            using type = z;
            using l1_carry = list<>;
            using l2_carry = list<>;
        };

        template<class, class, typename = true_>
        struct _large_partial_merge {};

        template<class... e1s, class... e2s>
        struct _large_partial_merge<
            list<e1s...>, list<e2s...>,
            number<(
                (sizeof...(e1s) >= 2) && (sizeof...(e2s) >= 2)
                && (sizeof...(e1s) + sizeof...(e2s)) > 512)>> {
            using l1 = list<e1s...>;
            using l2 = list<e2s...>;

            using l1_half1 = range<l1, number<0>, number<sizeof...(e1s) / 2>>;
            using l2_half1 = range<l2, number<0>, number<sizeof...(e2s) / 2>>;

            using l1_half2 =
                range<l1, number<sizeof...(e1s) / 2>, number<sizeof...(e1s)>>;
            using l2_half2 =
                range<l2, number<sizeof...(e2s) / 2>, number<sizeof...(e2s)>>;

            template<template<class...> class cmp>
            using sub_merge1 = _large_partial_merge<l1_half1, l2_half1>;

            template<template<class...> class cmp>
            using l1_half2_with_carry = join<
                typename sub_merge1<cmp>::template l1_carry<cmp>, l1_half2>;

            template<template<class...> class cmp>
            using l2_half2_with_carry = join<
                typename sub_merge1<cmp>::template l2_carry<cmp>, l2_half2>;

            template<template<class...> class cmp>
            using sub_merge2 = _large_partial_merge<
                l1_half2_with_carry<cmp>, l2_half2_with_carry<cmp>>;

            template<template<class...> class cmp>
            using type = join<
                typename sub_merge1<cmp>::template type<cmp>,
                typename sub_merge2<cmp>::template type<cmp>>;

            template<template<class...> class cmp>
            using l1_carry = typename sub_merge2<cmp>::template l1_carry<cmp>;

            template<template<class...> class cmp>
            using l2_carry = typename sub_merge2<cmp>::template l2_carry<cmp>;
        };

        template<class... e1s, class... e2s>
        struct _large_partial_merge<
            list<e1s...>, list<e2s...>,
            number<!(
                (sizeof...(e1s) >= 2) && (sizeof...(e2s) >= 2)
                && (sizeof...(e1s) + sizeof...(e2s)) > 512)>> {
            template<template<class...> class cmp>
            using type = typename _partial_merge<
                list<e1s...>, list<e2s...>, list<>, cmp>::type;

            template<template<class...> class cmp>
            using l1_carry = typename _partial_merge<
                list<e1s...>, list<e2s...>, list<>, cmp>::l1_carry;

            template<template<class...> class cmp>
            using l2_carry = typename _partial_merge<
                list<e1s...>, list<e2s...>, list<>, cmp>::l2_carry;
        };

        template<class l1, class l2, template<class...> class e>
        struct _merge {
            using sub_merge = _large_partial_merge<l1, l2>;
            using type = join<
                forward<sub_merge::template type, e>,
                forward<sub_merge::template l1_carry, e>,
                forward<sub_merge::template l2_carry, e>>;
        };

        template<typename seq>
        struct _sort_impl {};

        template<typename... vals>
        struct _sort_impl<list<vals...>> {
            using seq = list<vals...>;
            using beg = number<0>;
            using mid = number<sizeof...(vals) / 2>;
            using end = number<sizeof...(vals)>;

            template<template<typename...> class expr>
            using type = typename _merge<
                forward<_sort_impl<range<seq, beg, mid>>::template type, expr>,
                forward<_sort_impl<range<seq, mid, end>>::template type, expr>,
                expr>::type;
        };

        template<typename x, typename y>
        struct _sort_impl<list<x, y>> {
            template<template<typename...> class expr>
            using type = if_<expr<y, x>, list<y, x>, list<x, y>>;
        };

        template<typename x>
        struct _sort_impl<list<x>> {
            template<template<typename...> class>
            using type = list<x>;
        };

        template<>
        struct _sort_impl<list<>> {
            template<template<typename...> class>
            using type = list<>;
        };

        template<typename lbd>
        struct _sort {};

        template<template<typename...> class expr>
        struct _sort<lambda<expr>> {
            template<typename... seq>
            using type = forward<_sort_impl<seq...>::template type, expr>;
        };
    }
    /// \endcond
}

#endif
