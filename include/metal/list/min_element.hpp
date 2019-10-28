#ifndef METAL_LIST_MIN_ELEMENT_HPP
#define METAL_LIST_MIN_ELEMENT_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"
#include "../lambda/lambda.hpp"
#include "../number/less.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd = metal::lambda<metal::less>>
        struct _min_element;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Finds a minimum element in a \list according to an ordering relation.
    ///
    /// \note{The _first_ minimum element is returned if the ordering relation is [strict].}
    /// [strict]:
    /// https://en.wikipedia.org/wiki/Weak_ordering#Strict_weak_orderings
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::min_element<l, lbd>;
    /// \endcode
    ///
    /// \pre: `l` is not empty, and for any two \values `val_i` and `val_j`
    /// contained in `l` `metal::invoke<lbd, val_i, val_j>` returns a \number
    /// \returns: \value
    /// \semantics:
    ///     If `l` contains elements `val_0, ..., val_k, ..., val_m-1`, then
    ///     \code
    ///         using result = val_k;
    ///     \endcode
    ///     where `val_k` is an element in `l` such that
    ///       * `metal::invoke<lbd, val_k, val_j>{} != false` for all `j` in
    ///         `[0, k)` and
    ///       * `metal::invoke<lbd, val_i, val_k>{} == false` for all
    ///         `i` in `(k, m-1]`.
    ///
    /// \tip{`lbd` may be omitted, in which case it defaults to `metal::lambda<metal::less>`.}
    ///
    /// ### Example
    /// \snippet list.cpp min_element
    ///
    /// ### See Also
    /// \see min, sort
#if !defined(METAL_WORKAROUND)
    template<class seq, class lbd = metal::lambda<metal::less>>
    using min_element =
        detail::call<detail::_min_element<lbd>::template type, seq>;
#else
    // MSVC 14 has shabby SFINAE support in case of default alias template args
    template<class seq, class... lbd>
    using min_element =
        detail::call<detail::_min_element<lbd...>::template type, seq>;
#endif
}

#include "../list/list.hpp"
#include "../number/if.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class x, class y>
        struct _min_element_min_impl {
            template<template<class...> class expr>
            using type = if_<expr<y, x>, y, x>;
        };

        template<template<class...> class expr>
        struct _min_element_min {
            template<class x, class y>
            using type =
                forward<_min_element_min_impl<x, y>::template type, expr>;
        };

        template<class seq>
        struct _min_element_impl {};

        template<class... vals>
        struct _min_element_impl<list<vals...>> {
            template<template<class...> class expr>
            using type = fold_left<
                lambda<_min_element_min<expr>::template type>, vals...>;
        };

        template<class lbd>
        struct _min_element {};

        template<template<class...> class expr>
        struct _min_element<lambda<expr>> {
            template<class seq>
            using type = forward<_min_element_impl<seq>::template type, expr>;
        };
    }
    /// \endcond
}

#endif
