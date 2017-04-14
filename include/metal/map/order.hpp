// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_ORDER_HPP
#define METAL_MAP_ORDER_HPP

#include <metal/config.hpp>

#include <metal/map/keys.hpp>
#include <metal/map/at_key.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/transpose.hpp>
#include <metal/pair/pair.hpp>

namespace metal {
    /// \ingroup map
    ///
    /// ### Description
    /// Returns the index of a key in a \map.
    ///
    /// ### Usage
    /// For any \map `m` and \value `k`
    /// \code
    ///     using result = metal::order<m, k>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `m` contains an entry with key `k` at index `idx`, then
    ///     \code
    ///         using result = idx;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp order
    ///
    /// ### See Also
    /// \see map
    template<typename seq, typename key>
    using order = metal::at_key<
        metal::transpose<metal::pair<metal::keys<seq>, metal::indices<seq>>>,
        key
    >;
}

#endif
