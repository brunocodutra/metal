// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_DEC_HPP
#define METAL_NUMBER_DEC_HPP

#include "../config.hpp"
#include "../number/number.hpp"
#include "../number/sub.hpp"

namespace metal {
    /// \ingroup number
    ///
    /// ### Description
    /// Decrements a \number.
    ///
    /// ### Usage
    /// For any \number `num`
    /// \code
    ///     using result = metal::dec<num>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num{} - 1>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp dec
    ///
    /// ### See Also
    /// \see number, abs, inc, neg, add, sub, mul, div, mod, pow
    template<typename num>
    using dec = metal::sub<num, metal::number<1>>;
}

#endif
