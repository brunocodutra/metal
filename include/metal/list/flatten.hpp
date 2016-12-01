// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FLATTEN_HPP
#define METAL_LIST_FLATTEN_HPP

#include <metal/config.hpp>

#include <metal/list/join.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Collapses a \list of \lists into a flat \list that contains all the
    /// elements of the inner \lists preserving their order.
    ///
    /// ### Usage
    /// For any \list `l`
    /// \code
    ///     using result = metal::flatten<l>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[m-1]`, then
    ///     \code
    ///         using result = metal::list<l[0][:], ...[:], l[n-1][:]>;
    ///     \endcode
    ///     where the notation `l[:]` stands for the expansion of all elements
    ///     contained in `l`.
    ///
    /// ### Example
    /// \snippet list.cpp flatten
    ///
    /// ### See Also
    /// \see list, join
    template<typename seq>
    using flatten = metal::apply<metal::lambda<metal::join>, seq>;
}

#endif
