// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_LESS_HPP
#define METAL_NUMBER_COMPARISON_LESS_HPP

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct less;
    }

    /// \ingroup comparison
    /// Checks whether a \number is less than another.
    ///
    /// Usage
    /// -----
    /// For any \values `val1` and `val2`
    /// \code
    ///     metal::less<val1, val2>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If both `val1` and `val2` are \numbers, then equivalent to
    ///     \code
    ///         template<>
    ///         struct metal::less<val1, val2>
    ///             metal::boolean<(val1::value < val2::value)>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/comparison.cpp less
    ///
    /// See Also
    /// --------
    /// \see number, boolean, equal_to, greater
    template<typename x, typename y>
    using less = detail::less<x, y>;

    /// \ingroup comparison
    /// Eager adaptor for \ref less.
    template<typename x, typename y>
    using less_t = typename metal::less<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct less
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct less<number<tx, vx>, number<ty, vy>> :
            boolean<(vx < vy)>
        {};
    }
}

#endif
