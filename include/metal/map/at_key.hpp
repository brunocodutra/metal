// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_AT_KEY_HPP
#define METAL_MAP_AT_KEY_HPP

#include <metal/config.hpp>

#include <metal/map/keys.hpp>
#include <metal/map/values.hpp>

#include <metal/detail/lookup.hpp>

namespace metal
{
    /// \ingroup map
    ///
    /// ### Description
    /// Retrieves the value associated with some key in a \map.
    ///
    /// ### Usage
    /// For any \map `m` and \value `k`
    /// \code
    ///     using result = metal::at_key<m, k>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     If `m` associates keys `k_1, ..., k, ..., k_n` to values
    ///     `v_1, ..., v, ..., v_n`, then
    ///     \code
    ///         using result = v;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp at_key
    ///
    /// ### See Also
    /// \see map, has_key, erase_key
    template<typename seq, typename key>
    using at_key = detail::lookup<values<seq>, keys<seq>, key>;
}

#endif
