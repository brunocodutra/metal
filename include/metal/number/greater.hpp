// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_GREATER_HPP
#define METAL_NUMBER_GREATER_HPP

#include <metal/number/less.hpp>

namespace metal
{
    /// \ingroup number
    /// Checks whether a \number is greater than another.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1` and `num_2`
    /// \code
    ///     using result = metal::greater<num_1, num_2>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<(num_1{} > num_2{})>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp greater
    ///
    /// See Also
    /// --------
    /// \see number, less
    template<typename x, typename y>
    using greater = metal::less<y, x>;
}

#endif
