// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename lbd, typename seq>
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
    using apply = typename detail::_apply<lbd, seq>::type;
}

#include "../lambda/lambda.hpp"
#include "../list/list.hpp"
#include "../number/number.hpp"
#include "../value/value.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename lbd, typename seq, typename = true_>
        struct _apply_impl {};

        template<template<typename...> class expr, typename... vals>
        struct _apply_impl<
            lambda<expr>, list<vals...>, is_value<call<expr, vals...>>> {
            using type = expr<vals...>;
        };

        template<typename lbd, typename seq>
        struct _apply : _apply_impl<lbd, seq> {};
    }
    /// \endcond
}

#endif
