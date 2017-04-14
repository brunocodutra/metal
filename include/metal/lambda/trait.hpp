// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_TRAIT_HPP
#define METAL_LAMBDA_TRAIT_HPP

#include <metal/config.hpp>

#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>

namespace metal {
    /// \ingroup lambda
    ///
    /// ### Description
    /// Constructs a _predicate_ out of a _trait_, that is a \lambda that
    /// evaluates to a \number, out of an \expression that defines a nested
    /// integral constant `value` convertible to metal::int_.
    ///
    /// ### Usage
    /// For any \expression `expr`
    /// \code
    ///     using result = metal::trait<expr>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::lambda<pred>;
    ///     \endcode
    ///     where `pred` is an \expression such that
    ///     \code
    ///         template<typename... args>
    ///         using pred = metal::number<expr<args...>::value>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp trait
    ///
    /// ### See Also
    /// \see lambda, number
    template<template<typename...> class expr>
    using trait =
        metal::bind<metal::lambda<metal::as_number>, metal::lambda<expr>>;
}

#endif
