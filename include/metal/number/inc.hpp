// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_INC_HPP
#define METAL_NUMBER_INC_HPP

#include "../config.hpp"
#include "../number/add.hpp"
#include "../number/number.hpp"

namespace metal {
    /// \ingroup number
    ///
    /// ### Description
    /// Increments a \number.
    ///
    /// ### Usage
    /// For any \number `num`
    /// \code
    ///     using result = metal::inc<num>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num::{} + 1>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp inc
    ///
    /// ### See Also
    /// \see number, abs, dec, neg, add, sub, mul, div, mod, pow
    template<typename num>
    using inc = metal::add<num, metal::number<1>>;
}

#endif
