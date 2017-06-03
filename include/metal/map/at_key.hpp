// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_MAP_AT_KEY_HPP
#define METAL_MAP_AT_KEY_HPP

#include "../config.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename seq, typename key>
        struct _at_key;
    }
    /// \endcond

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
    /// \see map, has_key, insert_key, erase_key
    template<typename seq, typename key>
    using at_key = typename detail::_at_key<seq, key>::type;
}

#include "../list/list.hpp"
#include "../number/number.hpp"
#include "../value/distinct.hpp"
#include "../value/value.hpp"
#include "../detail/declptr.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename, typename = true_>
        struct table
        {};

        template<typename... keys, typename... vals>
        struct table<list<list<keys, vals>...>, distinct<list<keys, vals>...>> :
            list<keys, vals>...
        {};

        template<>
        struct table<list<>>
        {};

        template<typename key, typename val>
        value<val> lookup(list<key, val>*);

        template<typename>
        value<> lookup(...);

        template<typename seq, typename key>
        struct _at_key :
            decltype(lookup<key>(declptr<table<seq>>()))
        {};
    }
    /// \endcond
}

#endif
