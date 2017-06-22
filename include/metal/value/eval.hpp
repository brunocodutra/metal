// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_EVAL_HPP
#define METAL_VALUE_EVAL_HPP

#include "../config.hpp"

namespace metal {
    /// \ingroup value
    ///
    /// ### Description
    /// Evaluates _lazy_ constructs by retrieving their nested typename `type`.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::eval<val>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = typename val::type;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet value.cpp eval
    ///
    /// ### See Also
    /// \see value, lazy, id
    template<typename val>
    using eval = typename val::type;
}

#endif
