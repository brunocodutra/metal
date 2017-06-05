// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_OR_HPP
#define METAL_NUMBER_OR_HPP

#include "../config.hpp"
#include "../number/not.hpp"
#include "../number/number.hpp"
#include "../value/same.hpp"

namespace metal {
    /// \ingroup number
    ///
    /// ### Description
    /// Computes the logical disjunction of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::or_<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_0{} || ... || num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp or_
    ///
    /// ### See Also
    /// \see number, not_, and_
    template<typename... nums>
    using or_ = metal::not_<metal::same<metal::true_, metal::not_<nums>...>>;
}

#endif
