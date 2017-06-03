// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_ALWAYS_HPP
#define METAL_LAMBDA_ALWAYS_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename val>
        struct _always;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// Lifts a \value to an n-ary \lambda that always evaluates to that \value,
    /// regardless of the argument(s) it's [invoked](\ref invoke) with.
    ///
    /// ### Usage
    /// For any and \value `val`
    /// \code
    ///     using result = metal::always<val>;
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
    /// \snippet lambda.cpp always
    ///
    /// ### See Also
    /// \see lambda, invoke, partial, bind
    template<typename val>
    using always = typename detail::_always<val>::type;
}

#include "../lambda/lambda.hpp"
#include "../value/identity.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename val>
        struct _always
        {
            template<typename...>
            using impl = identity<val>;

            using type = lambda<impl>;
        };
    }
    /// \endcond
}

#endif
