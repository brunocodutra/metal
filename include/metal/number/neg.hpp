// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_NEG_HPP
#define METAL_NUMBER_NEG_HPP

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct _neg;
    }

    /// \ingroup number
    /// Computes the additive inverse of a \number.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     metal::neg<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \number, but not boolean, then equivalent to
    ///     \code
    ///         template<>
    ///         struct neg<val> :
    ///             number<val::value_type, -val::value>
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp neg
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, add, sub, mul, div, mod, pow
    template<typename num>
    using neg = typename detail::_neg<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct _neg
        {};

        template<bool v>
        struct _neg<bool_<v>>
        {};

        template<typename t, t v>
        struct _neg<number<t, v>> :
            number<t, static_cast<t>(0 - v)>
        {};
    }
}

#endif
