// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_INC_HPP
#define METAL_NUMBER_INC_HPP

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct _inc;
    }

    /// \ingroup number
    /// Increments a \number.
    ///
    /// Usage
    /// -----
    /// For any \number `num`
    /// \code
    ///     using result = metal::inc<num>;
    /// \endcode
    ///
    /// \pre: `num` is not a \number of type `bool`
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num::value_type, num::{} + 1>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp inc
    ///
    /// See Also
    /// --------
    /// \see number, dec, neg, add, sub, mul, div, mod, pow
    template<typename num>
    using inc = typename detail::_inc<num>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename num>
        struct _inc
        {};

        template<bool v>
        struct _inc<bool_<v>>
        {};

        template<typename t, t v>
        struct _inc<number<t, v>> :
            number<t, v + 1>
        {};
    }
}

#endif
