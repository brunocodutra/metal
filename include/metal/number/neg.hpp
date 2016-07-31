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
    /// For any \number `num`
    /// \code
    ///     using result = metal::neg<num>;
    /// \endcode
    ///
    /// \pre: `num` is not a \number of type `bool`
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num::value_type, -num{}>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp neg
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
