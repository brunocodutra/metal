// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COPY_HPP
#define METAL_LIST_COPY_HPP

#include <metal/config.hpp>

#include <metal/list/copy_if.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Removes all elements from a \list except for those that are the same as
    /// some \value.
    ///
    /// ### Usage
    /// For any \list `l` and \value `val`
    /// \code
    ///     using result = metal::copy<l, val>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` contains all and only the occurrences of `val` in
    ///     `l`.
    ///
    /// ### Example
    /// \snippet list.cpp copy
    ///
    /// ### See Also
    /// \see list, copy_if, remove, replace
    template<typename seq, typename val>
    using copy =
        metal::copy_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
