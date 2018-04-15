#ifndef METAL_MAP_KEYS_HPP
#define METAL_MAP_KEYS_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../list/transform.hpp"
#include "../map/map.hpp"
#include "../number/if.hpp"
#include "../pair/first.hpp"

namespace metal {
    /// \ingroup map
    ///
    /// ### Description
    /// Returns a \list of keys contained in a \map.
    ///
    /// ### Usage
    /// For any \map `m`
    /// \code
    ///     using result = metal::keys<m>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `m` associates keys `k_1, ..., k_n` to values `v_1, ..., v_n`,
    ///     then
    ///     \code
    ///         using result = metal::list<k_1, ..., k_n>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp keys
    ///
    /// ### See Also
    /// \see map, values
    template<typename seq>
    using keys = metal::if_<
        metal::is_map<seq>, metal::transform<metal::lambda<metal::first>, seq>>;
}

#endif
