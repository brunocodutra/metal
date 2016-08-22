// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_NEG_HPP
#define METAL_NUMBER_NEG_HPP

#include <metal/number/number.hpp>
#include <metal/number/sub.hpp>

namespace metal
{
    /// \ingroup number
    /// Computes the additive inverse of a \number.
    ///
    /// ### Usage
    /// For any \number `num`
    /// \code
    ///     using result = metal::neg<num>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<-num{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp neg
    ///
    /// ### See Also
    /// \see number, inc, dec, add, sub, mul, div, mod, pow
    template<typename num>
    using neg = metal::sub<metal::number<0>, num>;
}

#endif
