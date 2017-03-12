// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_IS_INVOCABLE_HPP
#define METAL_LAMBDA_IS_INVOCABLE_HPP

#include <metal/config.hpp>

#include <metal/lambda/invoke.hpp>
#include <metal/value/same.hpp>

#include <metal/detail/sfinae.hpp>

#include <type_traits>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct _is_invocable;
    }
    /// \endcond

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
        std::false_type,
        typename std::is_base_of<
            value<>,
            decltype(detail::sfinae<invoke, lbd, vals...>())
        >::type
    >;
}

#endif
