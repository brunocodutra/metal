// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_QUOTE_HPP
#define METAL_LAMBDA_QUOTE_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _quote;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// Lifts a \value to an n-ary \lambda that always evaluates to that \value.
    ///
    /// ### Usage
    /// For any and \value `val`
    /// \code
    ///     using result = metal::quote<val>;
    /// \endcode
    ///
    /// \returns: \lambda
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::lambda<expr>;
    ///     \endcode
    ///     where `expr` is an \expression such that
    ///     \code
    ///         template<typename...>
    ///         using expr = val;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet lambda.cpp quote
    ///
    /// ### See Also
    /// \see lambda, invoke, partial, bind
    template<typename val>
    using quote = typename detail::_quote<val>::type;
}

#include <metal/lambda/lambda.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _quote
        {
#if defined(METAL_COMPAT_MODE)
            template<typename...>
            struct _impl
            {
                using type = val;
            };

            template<typename... vals>
            using impl = typename _impl<vals...>::type;
#else
            template<typename...>
            using impl = val;
#endif
            using type = lambda<impl>;
        };
    }
    /// \endcond
}

#endif
