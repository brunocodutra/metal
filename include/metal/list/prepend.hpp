// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_PREPEND_HPP
#define METAL_LIST_PREPEND_HPP

#include <metal/config.hpp>

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Inserts \values at the beginning of a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::prepend<l, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::list<
    ///             val_0, ..., val_n-1, l[0], ..., l[m-1]
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp prepend
    ///
    /// ### See Also
    /// \see list, insert, append
    template<typename seq, typename head, typename... tail>
    using prepend = metal::join<metal::list<head, tail...>, seq>;
}

#endif
