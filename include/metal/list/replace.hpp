// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REPLACE_HPP
#define METAL_LIST_REPLACE_HPP

#include <metal/config.hpp>

#include <metal/list/replace_if.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Replaces every occurrence of a \value in a \list by another \value.
    ///
    /// ### Usage
    /// For any \list `l` and \values `val_1` and `val_2`
    /// \code
    ///     using result = metal::replace<l, val_1, val_2>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` contains all and only the elements in `l`, except
    ///     that every occurrence of `val_1` has been replaced by `val_2`.
    ///
    /// ### Example
    /// \snippet list.cpp replace
    ///
    /// ### See Also
    /// \see list, replace_if, copy, remove
    template<typename seq, typename from, typename to>
    using replace = metal::replace_if<
        seq, metal::partial<metal::lambda<metal::same>, from>, to
    >;
}

#endif
