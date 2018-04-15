#ifndef METAL_MAP_HAS_KEY_HPP
#define METAL_MAP_HAS_KEY_HPP

#include "../config.hpp"
#include "../list/contains.hpp"
#include "../map/keys.hpp"

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
