// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_EMPTY_HPP
#define METAL_LIST_EMPTY_HPP

#include <metal/config.hpp>

#include <metal/list/size.hpp>
#include <metal/number/not.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Checks whether a \list has no elements.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::empty<l>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `l` contains at least one element, then
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp empty
    ///
    /// ### See Also
    /// \see list, size
    template<typename seq>
    using empty = metal::not_<metal::size<seq>>;
}

#endif
