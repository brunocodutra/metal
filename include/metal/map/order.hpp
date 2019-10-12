#ifndef METAL_MAP_ORDER_HPP
#define METAL_MAP_ORDER_HPP

#include "../config.hpp"
#include "../list/indices.hpp"
#include "../list/transpose.hpp"
#include "../map/at_key.hpp"
#include "../map/keys.hpp"
#include "../pair/pair.hpp"

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
    template<class seq, class key>
    using order = metal::at_key<
        metal::transpose<metal::pair<metal::keys<seq>, metal::indices<seq>>>,
        key>;
}

#endif
