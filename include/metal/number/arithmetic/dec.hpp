// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_DEC_HPP
#define METAL_NUMBER_ARITHMETIC_DEC_HPP

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct dec;
    }

    /// \ingroup arithmetic
    /// Decrements a \number.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     using result = metal::dec<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \number, but not a boolean, then equivalent to
    ///     \code
    ///         struct result :
    ///             metal::number<val::value_type, val::value - 1>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp dec
    ///
    /// See Also
    /// --------
    /// \see number, inc, neg, add, sub, mul, div, mod, pow
    template<typename num>
    using dec = detail::dec<num>;

    /// \ingroup arithmetic
    /// Eager adaptor for \ref dec.
    template<typename num>
    using dec_t = typename metal::dec<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct dec
        {};

        template<bool v>
        struct dec<boolean<v>>
        {};

        template<typename t, t v>
        struct dec<number<t, v>> :
            number<t, static_cast<t>(v - t(1))>
        {};
    }
}

#endif
