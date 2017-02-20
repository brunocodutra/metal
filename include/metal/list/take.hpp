// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_TAKE_HPP
#define METAL_LIST_TAKE_HPP

#include <metal/config.hpp>

#include <metal/list/range.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Removes all elements from the end down to an arbitrary index of a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \number `num`
    /// \code
    ///     using result = metal::take<l, num>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; num{} &le; metal::size<l>{}`
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
    ///     `num{} == i`, then
    ///     \code
    ///         using result = metal::list<l[0], ..., l[i-1]>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp take
    ///
    /// ### See Also
    /// \see list, range, erase, drop
    template<typename seq, typename n>
    using take = metal::range<seq, metal::number<0>, n>;
}

#endif
