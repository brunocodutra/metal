// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename lbd>
        struct _apply;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// [Invokes](\ref invoke) a \lambda with the \values contained in a \list.
    ///
    /// ### Usage
    /// For any \lambda `lbd` and \list `l`
    /// \code
    ///     using result = metal::apply<lbd, l>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::invoke<lbd, l[0], ..., l[m-1]>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp apply
    ///
    /// ### See Also
    /// \see lambda, invoke, list
    template<typename lbd, typename seq>
    using apply = detail::call<detail::_apply<lbd>::template type, seq>;
}

#include "../lambda/lambda.hpp"
#include "../list/list.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename seq>
        struct _apply_impl {};

        template<typename... vals>
        struct _apply_impl<list<vals...>> {
            template<template<typename...> class expr>
            using type =
#if defined(METAL_WORKAROUND)
                call<expr, vals...>;
#else
                expr<vals...>;
#endif
        };

        template<typename lbd>
        struct _apply {};

        template<template<typename...> class expr>
        struct _apply<lambda<expr>> {
            template<typename seq>
            using type = forward<_apply_impl<seq>::template type, expr>;
        };
    }
    /// \endcond
}

#endif
