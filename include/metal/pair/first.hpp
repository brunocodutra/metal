// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_PAIR_FIRST_HPP
#define METAL_PAIR_FIRST_HPP

#include <metal/config.hpp>

#include <metal/pair/pair.hpp>
#include <metal/list/front.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup pair
    ///
    /// ### Description
    /// Returns the first element of a \pair.
    ///
    /// ### Usage
    /// For any \pair `p`
    /// \code
    ///     using result = metal::first<p>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `p` contains \values `x` and `y` in that order, then
    ///     \code
    ///         using result = x;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet pair.cpp first
    ///
    /// ### See Also
    /// \see pair, second
    template<typename seq>
    using first = metal::if_<metal::is_pair<seq>, metal::front<seq>>;
}

#endif
