// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_ABS_HPP
#define METAL_NUMBER_ABS_HPP

#include "../config.hpp"
#include "../number/max.hpp"
#include "../number/neg.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \ingroup number
    ///
    /// ### Description
    /// Computes absolute value of a \number.
    ///
    /// ### Usage
    /// For any \number `num`
    /// \code
    ///     using result = metal::abs<num>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<(num{} > 0) ? num{} : -num{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp abs
    ///
    /// ### See Also
    /// \see number, inc, dec, neg, add, sub, mul, div, mod, pow
    template<typename num>
    using abs = metal::max<num, metal::neg<num>>;
}

#endif
