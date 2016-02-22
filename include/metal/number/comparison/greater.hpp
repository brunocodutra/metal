// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_COMPARISON_GREATER_HPP
#define METAL_NUMBER_COMPARISON_GREATER_HPP

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct greater;
    }

    /// \ingroup comparison
    /// Checks whether a \number is greater than another.
    ///
    /// Usage
    /// -----
    /// For any \values `val1` and `val2`
    /// \code
    ///     using result = metal::greater<val1, val2>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If both `val1` and `val2` are \numbers, then equivalent to
    ///     \code
    ///         struct result :
    ///             metal::boolean<(val1::value > val2::value)>
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
    using greater = detail::greater<x, y>;

    /// \ingroup comparison
    /// Eager adaptor for \ref greater.
    template<typename x, typename y>
    using greater_t = typename metal::greater<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct greater
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct greater<number<tx, vx>, number<ty, vy>> :
            boolean<(vx > vy)>
        {};
    }
}

#endif
