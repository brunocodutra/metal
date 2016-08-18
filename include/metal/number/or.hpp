// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_OR_HPP
#define METAL_NUMBER_OR_HPP

#include <metal/number/number.hpp>
#include <metal/number/not.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    /// \ingroup number
    /// Computes the logical disjunction of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1, ..., num_n`
    /// \code
    ///     using result = metal::or_<num_1, ..., num_n>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_1{} || ... || num_n{}>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp or_
    ///
    /// See Also
    /// --------
    /// \see number, not_, and_
    template<typename... nums>
    using or_ = metal::not_<metal::same<metal::true_, metal::not_<nums>...>>;
}

#endif
