// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/config.hpp>

#include <metal/lambda/invoke.hpp>

namespace metal
{
    /// \ingroup lambda
    ///
    /// ### Description
    /// Invokes a \lambda with the \values contained in a \list.
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
    using apply = typename detail::_invoke_impl<lbd, seq>::type;
}

#endif

