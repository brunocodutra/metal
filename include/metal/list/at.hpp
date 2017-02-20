// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP

#include <metal/config.hpp>

#include <metal/list/indices.hpp>

#include <metal/detail/lookup.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Retrieves an element of a \list at an arbitrary position.
    ///
    /// ### Usage
    /// For any \list `l` and \number `num`
    /// \code
    ///     using result = metal::at<l, num>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; num{} < metal::size<l>{}`
    /// \returns: \value
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
    ///     `num{} == i`, then
    ///     \code
    ///         using result = l[i];
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp at
    ///
    /// ### See Also
    /// \see list, front, back
    template<typename seq, typename num>
    using at = detail::lookup<seq, indices<seq>, num>;
}

#endif
