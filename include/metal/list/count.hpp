// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COUNT_HPP
#define METAL_LIST_COUNT_HPP

#include <metal/config.hpp>

#include <metal/list/count_if.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/value/same.hpp>

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Counts the occurrences of a \value in a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \value `val`
    /// \code
    ///     using result = metal::count<l, val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<n>;
    ///     \endcode
    ///     where `n` is the number of occurrences of `val` in `l`.
    ///
    /// ### Example
    /// \snippet list.cpp count
    ///
    /// ### See Also
    /// \see list, count_if, contains, find
    template<typename seq, typename val>
    using count =
        metal::count_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
