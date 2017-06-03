// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REVERSE_HPP
#define METAL_LIST_REVERSE_HPP

#include "../config.hpp"
#include "../list/list.hpp"
#include "../list/size.hpp"
#include "../list/range.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Reverses the order of the elements of a \list.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::reverse<l>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::list<l[m-1], ..., l[0]>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp reverse
    ///
    /// ### See Also
    /// \see list, rotate, sort
    template<typename seq>
    using reverse = metal::range<seq, metal::size<seq>, metal::number<0>>;
}

#endif
