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
    /// For any \values `val1` and `val2`
    /// \code
    ///     metal::greater<val1, val2>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If both `val1` and `val2` are \numbers, then equivalent to
    ///     \code
    ///         template<>
    ///         struct greater<val1, val2> :
    ///             bool_<(val1::value > val2::value)>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/comparison.cpp greater
    ///
    /// See Also
    /// --------
    /// \see number, boolean, equal_to, less
    template<typename x, typename y>
    using greater = less<y, x>;
}

#endif
