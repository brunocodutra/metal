// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_ABS_HPP
#define METAL_NUMBER_ABS_HPP

#include <metal/config.hpp>

#include <metal/number/number.hpp>
#include <metal/number/max.hpp>
#include <metal/number/neg.hpp>

namespace metal
{
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
