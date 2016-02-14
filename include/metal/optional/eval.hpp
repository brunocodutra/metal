// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_EVAL_HPP
#define METAL_OPTIONAL_EVAL_HPP

#include <metal/optional/conditional.hpp>
#include <metal/optional/optional.hpp>

#include <metal/detail/nil.hpp>

namespace metal
{
    /// \ingroup optional
    /// Evaluates an \optional.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`
    /// \code
    ///     using result = metal::eval<opt>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = typename opt::type
    ///     \endcode
    ///
    /// \danger{Evaluating an empty optional leads to a compile time error.}
    ///
    /// ________________________________________________________________________
    ///
    /// For any \optional `opt` and \value `val`
    /// \code
    ///     using result = metal::eval<opt, val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::conditional_t<metal::is_just_t<opt>, opt, metal::just<val>>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet optional/eval.cpp eval
    ///
    /// See Also
    /// --------
    /// \see conditional, just, is_just
    template<typename opt, typename fallback = detail::nil>
    using eval = metal::conditional_t<
        metal::is_just_t<opt>, opt, metal::just<fallback>
    >;
}

#endif
