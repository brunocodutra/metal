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
        template<typename lbd, typename... vals>
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
    template<typename lbd, typename... vals>
    using invoke = typename detail::_invoke<lbd, vals...>::type;

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
    template<typename lbd, typename... vals>
    using is_invocable = same<
        typename std::is_base_of<
            value<>,
            detail::_invoke<lbd, vals...>
        >::type,
        std::false_type
    >;
}

#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
#if defined(METAL_COMPAT_MODE)
        template<template<typename...> class expr, typename... vals,
            typename std::enable_if<
                is_value<expr<vals...>>::value
            >::type* = nullptr
        >
        value<expr<vals...>> invoke_impl(lambda<expr>*, list<vals...>*);

        value<> invoke_impl(...);

        template<typename lbd, typename seq>
        struct _invoke_impl :
            value<>
        {};

        template<template<typename...> class expr, typename... vals>
        struct _invoke_impl<lambda<expr>, list<vals...>> :
            decltype(invoke_impl(
                declptr<lambda<expr>>(),
                declptr<list<vals...>>()
            ))
        {};
#else
        template<typename lbd, typename seq, typename = true_>
        struct _invoke_impl :
            value<>
        {};

        template<template<typename...> class expr, typename... vals>
        struct _invoke_impl<lambda<expr>, list<vals...>,
            is_value<expr<vals...>>
        > :
            value<expr<vals...>>
        {};
#endif

        template<typename lbd, typename... vals>
        struct _invoke :
            _invoke_impl<lbd, list<vals...>>
        {};
    }
    /// \endcond
}

#endif
