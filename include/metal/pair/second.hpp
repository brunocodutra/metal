// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_PAIR_SECOND_HPP
#define METAL_PAIR_SECOND_HPP

#include "../config.hpp"
#include "../list/back.hpp"
#include "../number/if.hpp"
#include "../pair/pair.hpp"

namespace metal {
    /// \ingroup pair
    ///
    /// ### Description
    /// Retrieves the second element of a \pair.
    ///
    /// ### Usage
    /// For any \pair `p`
    /// \code
    ///     using result = metal::second<p>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `p` contains \values `p_0` and `p_1` in that order, then
    ///     \code
    ///         using result = p_1;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet pair.cpp second
    ///
    /// ### See Also
    /// \see pair, first
    template<typename seq>
    using second = metal::if_<metal::is_pair<seq>, metal::back<seq>>;
}

#endif
