// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_DEC_HPP
#define METAL_NUMBER_DEC_HPP

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct _dec;
    }

    /// \ingroup number
    /// Decrements a \number.
    ///
    /// Usage
    /// -----
    /// For any \value `val`
    /// \code
    ///     metal::dec<val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val` is a \number, but not a boolean, then equivalent to
    ///     \code
    ///         template<>
    ///         struct dec<val> :
    ///             number<val::value_type, val::value - 1>
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
    using dec = typename detail::_dec<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct _dec
        {};

        template<bool v>
        struct _dec<bool_<v>>
        {};

        template<typename t, t v>
        struct _dec<number<t, v>> :
            number<t, v - 1>
        {};
    }
}

#endif
