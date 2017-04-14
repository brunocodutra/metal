// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_GREATER_HPP
#define METAL_NUMBER_GREATER_HPP

#include <metal/config.hpp>

#include <metal/number/less.hpp>

namespace metal {
    /// \ingroup number
    ///
    /// ### Description
    /// Checks whether a \number is greater than another.
    ///
    /// ### Usage
    /// For any \numbers `x` and `y`
    /// \code
    ///     using result = metal::greater<x, y>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<(x{} > y{})>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp greater
    ///
    /// ### See Also
    /// \see number, less, max, min
    template<typename x, typename y>
    using greater = metal::less<y, x>;
}

#endif
