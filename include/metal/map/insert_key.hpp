#ifndef METAL_MAP_INSERT_KEY_HPP
#define METAL_MAP_INSERT_KEY_HPP

#include "../config.hpp"
#include "../list/append.hpp"
#include "../map/has_key.hpp"
#include "../number/if.hpp"
#include "../pair/pair.hpp"

namespace metal {
    /// \ingroup map
    ///
    /// ### Description
    /// Inserts a new entry in a \map.
    ///
    /// ### Usage
    /// For any \map `m` and \values `k` and `v`
    /// \code
    ///     using result = metal::erase_key<m, k, v>;
    /// \endcode
    ///
    /// \pre: `k` is not contained in `metal::keys<m>`
    /// \returns: \map
    /// \semantics:
    ///     If `m` associates keys `k_1, ..., k_n` to values `v_1, ..., v_n`,
    ///     then
    ///     \code
    ///         using result = metal::map<
    ///             metal::pair<k_1, v_1>,
    ///             ...,
    ///             metal::pair<k_n, v_n>,
    ///             metal::pair<k, v>
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp insert_key
    ///
    /// ### See Also
    /// \see map, has_key, at_key, erase_key
    template<typename seq, typename key, typename val>
    using insert_key = metal::if_<
        metal::not_<metal::has_key<seq, key>>,
        metal::append<seq, metal::pair<key, val>>>;
}

#endif
