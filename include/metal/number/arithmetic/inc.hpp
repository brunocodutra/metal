// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_INC_HPP
#define METAL_NUMBER_ARITHMETIC_INC_HPP

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct inc;
    }

    /// \ingroup arithmetic
    /// Increments a \number.
    ///
    /// Usage
    /// -----
    /// For any \val `val`
    /// \code
    ///     using result = metal::inc<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \number, then equivalent to
    ///     \code
    ///         using result = metal::number<typename val::value_type, val::value + 1>;
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         using result = metal::nothing;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp inc
    ///
    /// See Also
    /// --------
    /// \see number, dec, neg, add, sub, mul, div, mod
    template<typename num>
    using inc = detail::inc<num>;

    /// \ingroup arithmetic
    /// Eager adaptor for \ref inc.
    template<typename num>
    using inc_t = typename metal::inc<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct inc
        {};

        template<typename t, t v>
        struct inc<number<t, v>> :
            number<t, static_cast<t>(v + t(1))>
        {};
    }
}

#endif
