// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_INC_HPP
#define METAL_NUMBER_INC_HPP

#include <metal/config.hpp>

#include <metal/number/number.hpp>
#include <metal/number/add.hpp>

namespace metal
{
    /// \ingroup number
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
    ///     \code
    ///         using result = metal::number<num::{} + 1>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp inc
    ///
    /// ### See Also
    /// \see number, dec, neg, add, sub, mul, div, mod, pow
    template<typename num>
    using inc = metal::add<num, metal::number<1>>;
}

#endif
