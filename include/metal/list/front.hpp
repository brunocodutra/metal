// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FRONT_HPP
#define METAL_LIST_FRONT_HPP

#include "../config.hpp"
#include "../list/at.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Retrieves the first element of a \list.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::front<l>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = l[0];
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp front
    ///
    /// ### See Also
    /// \see list, at, back
    template<typename seq>
    using front = metal::at<seq, metal::number<0>>;
}

#endif
