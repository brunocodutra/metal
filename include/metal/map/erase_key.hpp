// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_ERASE_KEY_HPP
#define METAL_MAP_ERASE_KEY_HPP

#include "../config.hpp"
#include "../list/erase.hpp"
#include "../map/order.hpp"

namespace metal {
    /// \ingroup map
    ///
    /// ### Description
    /// Removes the entry associated with some key in a \map.
    ///
    /// ### Usage
    /// For any \map `m` and \value `k`
    /// \code
    ///     using result = metal::erase_key<m, k>;
    /// \endcode
    ///
    /// \returns: \map
    /// \semantics:
    ///     If `m` associates keys `k_1, ..., k, ..., k_n` to values
    ///     `v_1, ..., v, ..., v_n`, then
    ///     \code
    ///         using result = metal::map<
    ///             metal::pair<k_1, v_1>, ..., metal::pair<k_n, v_n>
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp erase_key
    ///
    /// ### See Also
    /// \see map, has_key, at_key, insert_key
    template<typename seq, typename key>
    using erase_key = metal::erase<seq, metal::order<seq, key>>;
}

#endif
