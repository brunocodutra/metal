// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_LESS_HPP
#define METAL_NUMBER_LESS_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename x, typename y>
        struct _less;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Checks whether a \number is less than another.
    ///
    /// ### Usage
    /// For any \numbers `x` and `y`
    /// \code
    ///     using result = metal::less<x, y>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<(x{} < y{})>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp less
    ///
    /// ### See Also
    /// \see number, greater, max, min
    template<typename x, typename y>
    using less = typename detail::_less<x, y>::type;
}

#include "../number/number.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename x, typename y>
        struct _less {};

        template<int_ x, int_ y>
        struct _less<number<x>, number<y>> : number<(x < y)> {};
    }
    /// \endcond
}

#endif
