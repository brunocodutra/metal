// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REMOVE_IF_HPP
#define METAL_LIST_REMOVE_IF_HPP

#include <metal/config.hpp>

#include <metal/list/replace_if.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Removes all elements from a \list that satisfy a predicate.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::remove_if<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` contains all and only the elements `l[i]` in `l` for
    ///     which `metal::invoke<lbd, l[i]>{} == false`.
    ///
    /// ### Example
    /// \snippet list.cpp remove_if
    ///
    /// ### See Also
    /// \see list, remove, copy_if, replace_if
    template<typename seq, typename lbd>
    using remove_if = metal::replace_if<seq, lbd>;
}

#endif
