// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_INDICES_HPP
#define METAL_LIST_INDICES_HPP

#include <metal/config.hpp>

#include <metal/list/size.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Replaces each element of a \list by its corresponding index.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::indices<l>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::list<
    ///             metal::number<0>, metal::number<>..., metal::number<m-1>
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp indices
    ///
    /// ### See Also
    /// \see list, enumerate
    template<typename seq>
    using indices = metal::enumerate<metal::number<0>, metal::size<seq>>;
}

#endif
