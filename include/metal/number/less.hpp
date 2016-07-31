// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_LESS_HPP
#define METAL_NUMBER_LESS_HPP

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct _less;
    }

    /// \ingroup number
    /// Checks whether a \number is less than another.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1` and `num_2`
    /// \code
    ///     using result = metal::less<num_1, num_2>;
    /// \endcode
    ///
    /// \returns: \number of type `bool`
    /// \semantics:
    ///     \code
    ///         using result = metal::bool_<(num_1{} < num_2{})>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp less
    ///
    /// See Also
    /// --------
    /// \see number, greater
    template<typename x, typename y>
    using less = typename detail::_less<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct _less
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct _less<number<tx, vx>, number<ty, vy>> :
            bool_<(vx < vy)>
        {};
    }
}

#endif
