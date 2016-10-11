// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COUNT_IF_HPP
#define METAL_LIST_COUNT_IF_HPP

#include <metal/config.hpp>

#include <metal/list/transform.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/number.hpp>
#include <metal/number/add.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Counts the elements in a \list that satisfy a predicate.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::count_if<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<n>;
    ///     \endcode
    ///     where `n` is the number of occurrences of some `l[i]` in `l`, such
    ///     that `metal::invoke<lbd, l[i]>{} != false`.
    ///
    /// ### Example
    /// \snippet list.cpp count_if
    ///
    /// ### See Also
    /// \see list, count, all, any, none, find_if
    template<typename seq, typename lbd>
    using count_if = metal::apply<
        metal::partial<metal::lambda<metal::add>, metal::number<0>>,
        metal::transform<lbd, seq>
    >;
}

#endif
