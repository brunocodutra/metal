// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_EQUAL_TO_HPP
#define METAL_NUMBER_COMPARISON_EQUAL_TO_HPP

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct equal_to;
    }

    /// \ingroup comparison
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
    ///         struct metal::equal_to<val1, val2>
    ///             metal::boolean<val1::value == val2::value>
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
    using equal_to = detail::equal_to<x, y>;

    /// \ingroup comparison
    /// Eager adaptor for \ref equal_to.
    template<typename x, typename y>
    using equal_to_t = typename metal::equal_to<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct equal_to
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct equal_to<number<tx, vx>, number<ty, vy>> :
            boolean<(vx == vy)>
        {};
    }
}

#endif
