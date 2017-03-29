// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_LAZY_HPP
#define METAL_LAMBDA_LAZY_HPP

#include <metal/config.hpp>

#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/value/eval.hpp>

namespace metal
{
    /// \ingroup lambda
    ///
    /// ### Description
    /// Constructs a \lambda out of a _lazy expression_, that is, an
    /// \expression whose return \value is defined as a nested typename `type`.
    ///
    /// ### Usage
    /// For any \expression `expr`
    /// \code
    ///     using result = metal::lazy<expr>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::lambda<eager>;
    ///     \endcode
    ///     where `eager` is an \expression such that
    ///     \code
    ///         template<typename... args>
    ///         using eager = typename expr<args...>::type;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp lazy
    ///
    /// ### See Also
    /// \see lambda, eval
    template<template<typename...> class expr>
    using lazy = metal::bind<metal::lambda<metal::eval>, metal::lambda<expr>>;
}

#endif
