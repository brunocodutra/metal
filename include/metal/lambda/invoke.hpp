// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

#include <metal/config.hpp>

#include <metal/value/value.hpp>
#include <metal/value/same.hpp>

#include <type_traits>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename... args>
        struct _invoke;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// Invokes a \lambda with some \values.
    ///
    /// ### Usage
    /// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::invoke<lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `lbd` holds \expression `expr`, then
    ///     \code
    ///         using result = expr<val_0, ..., val_n-1>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp invoke
    ///
    /// ### See Also
    /// \see lambda, is_invocable
    template<typename lbd, typename... args>
    using invoke = typename detail::_invoke<lbd, args...>::type;

    /// \ingroup lambda
    ///
    /// ### Description
    /// Checks whether a \lambda is invocable with some \values.
    ///
    /// ### Usage
    /// For any \lambda `lbd` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::is_invocable<lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `lbd` holds \expression `expr`, and `expr<val_0, ..., val_n-1>`
    ///     is well defined after template substitution, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp is_invocable
    ///
    /// ### See Also
    /// \see lambda, invoke
    template<typename lbd, typename... args>
    using is_invocable = same<
        typename std::is_base_of<
            value<>,
            detail::_invoke<lbd, args...>
        >::type,
        std::false_type
    >;
}

#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename seq, typename = true_>
        struct _invoke_impl :
            value<>
        {};

        template<
            template<typename...> class expr,
            typename head, typename... tail
        >
        struct _invoke_impl<lambda<expr>, list<head, tail...>,
            is_value<expr<head, tail...>>
        > :
            value<expr<head, tail...>>
        {};

        template<template<typename...> class expr>
        struct _invoke_impl<lambda<expr>, list<>,
            is_value<expr<>>
        > :
            value<expr<>>
        {};

        template<typename lbd, typename... args>
        struct _invoke :
            _invoke_impl<lbd, list<args...>>
        {};
    }
    /// \endcond
}

#endif
