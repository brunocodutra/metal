// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_EQUAL_TO_HPP
#define METAL_NUMBER_EQUAL_TO_HPP

#include <metal/number/less.hpp>
#include <metal/number/not.hpp>
#include <metal/number/or.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct _equal_to;
    }

    /// \ingroup number
    /// Checks whether two \numbers are equal.
    ///
    /// Usage
    /// -----
    /// For any \values `val1` and `val2`
    /// \code
    ///     metal::equal_to<val1, val2>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If both `val1` and `val2` are \numbers, then equivalent to
    ///     \code
    ///         template<>
    ///         struct equal_to<val1, val2> :
    ///             bool_<val1::value == val2::value>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/comparison.cpp equal_to
    ///
    /// See Also
    /// --------
    /// \see number, boolean, greater, less
    template<typename x, typename y>
    using equal_to = not_<or_<less<x, y>, less<y, x>>>;
}

#endif
