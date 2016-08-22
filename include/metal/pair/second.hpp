// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_PAIR_SECOND_HPP
#define METAL_PAIR_SECOND_HPP

#include <metal/pair/pair.hpp>
#include <metal/list/back.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup pair
    /// Returns the second element of a \pair.
    ///
    /// ### Usage
    /// For any \pair `pair`
    /// \code
    ///     using result = metal::second<pair>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `pair` contains \values `x` and `y` in that order, then
    ///     \code
    ///         using result = y;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet pair.cpp second
    ///
    /// ### See Also
    /// \see pair, first, at
    template<typename seq>
    using second = metal::if_<metal::is_pair<seq>, metal::back<seq>>;
}

#endif
