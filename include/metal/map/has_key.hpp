// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_HAS_KEY_HPP
#define METAL_MAP_HAS_KEY_HPP

#include <metal/config.hpp>

#include <metal/map/keys.hpp>
#include <metal/list/contains.hpp>

namespace metal {
    /// \ingroup map
    ///
    /// ### Description
    /// Checks whether a \map contains an entry with some key.
    ///
    /// ### Usage
    /// For any \map `m` and \value `k`
    /// \code
    ///     using result = metal::has_key<m, k>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `m` contains an entry with key `k`, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp has_key
    ///
    /// ### See Also
    /// \see map, at_key, insert_key, erase_key
    template<typename seq, typename key>
    using has_key = metal::contains<metal::keys<seq>, key>;
}

#endif
