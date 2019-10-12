#ifndef METAL_LIST_ACCUMULATE_HPP
#define METAL_LIST_ACCUMULATE_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"
#include "../list/size.hpp"
#include "../number/if.hpp"
#include "../value/same.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd>
        struct _accumulate;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Computes the recursive invocation of a binary \lambda with the result of
    /// the previous invocation and each element of one or more \lists traversed
    /// in parallel from the beginning to the end.
    ///
    /// ### Usage
    /// For any \lambda `lbd`, \value `val` and \lists `l_0, ..., l_n-1`
    /// \code
    ///     using result = metal::accumulate<lbd, val, l_0, ..., l_n-1>;
    /// \endcode
    ///
    /// \pre: `metal::size<l_0>{} == metal::size<>{}... == metal::size<l_n-1>{}`
    /// \returns: \value
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result =
    ///             lbd(... lbd(lbd(val, l[0]...), l[1]...), ..., l[m-1]...)
    ///     \endcode
    ///     where `l[N]...` stands for `l_0[N], ...[N], l_n-1[N]` and
    ///     `lbd(x, y)` stands for `metal::invoke<lbd, x, y>`.
    ///
    /// ### Example
    /// \snippet list.cpp accumulate
    ///
    /// ### See Also
    /// \see list, transform, fold_left
    template<class lbd, class state, class... seqs>
    using accumulate = detail::call<
        if_<same<size<seqs>...>, detail::_accumulate<lbd>>::template type,
        state, seqs...>;
}

#include "../lambda/lambda.hpp"
#include "../list/at.hpp"
#include "../list/indices.hpp"
#include "../list/list.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class state, class num, class... seqs>
        struct accumulator_impl {
            template<template<class...> class expr>
            using type = expr<state, at<seqs, num>...>;
        };

        template<template<class...> class expr, class... seqs>
        struct accumulator {
            template<class state, class num>
            using type = forward<
                accumulator_impl<state, num, seqs...>::template type, expr>;
        };

        template<class state, class head, class... tail>
        struct _accumulate_impl {
            template<template<class...> class expr>
            using type = forward<
                _accumulate_impl<state, indices<head>>::template type,
                accumulator<expr, head, tail...>::template type>;
        };

        template<class state, class... vals>
        struct _accumulate_impl<state, list<vals...>> {
            template<template<class...> class expr>
            using type = fold_left<lambda<expr>, state, vals...>;
        };

        template<class lbd>
        struct _accumulate {};

        template<template<class...> class expr>
        struct _accumulate<lambda<expr>> {
            template<class state, class... seqs>
            using type =
                forward<_accumulate_impl<state, seqs...>::template type, expr>;
        };
    }
    /// \endcond
}

#endif
