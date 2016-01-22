// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_NEG_HPP
#define METAL_NUMBER_ARITHMETIC_NEG_HPP

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct neg;
    }

    /// \ingroup arithmetic
    /// Computes the additive inverse of a \number.
    ///
    /// Usage
    /// -----
    /// For any \val `val`
    /// \code
    ///     using result = metal::neg<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \number, but not boolean, then equivalent to
    ///     \code
    ///         using result = metal::number<typename val::value_type, -val::value>;
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         using result = metal::nothing;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp neg
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, add, sub, mul, div, mod
    template<typename num>
    using neg = detail::neg<num>;

    /// \ingroup arithmetic
    /// Eager adaptor for \ref neg.
    template<typename num>
    using neg_t = typename metal::neg<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct neg
        {};

        template<bool v>
        struct neg<boolean<v>>
        {};

        template<typename t, t v>
        struct neg<number<t, v>> :
            number<t, static_cast<t>(t(0) - v)>
        {};
    }
}

#endif
