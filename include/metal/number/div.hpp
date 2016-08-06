// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_DIV_HPP
#define METAL_NUMBER_DIV_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _div;
    }

    /// \ingroup number
    /// Computes the quotient of the arithmetic division of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1, ..., num_n`
    /// \code
    ///     using result = metal::div<num_1, ..., num_n>;
    /// \endcode
    ///
    /// \pre: all \numbers in `[num_2, ..., num_n]` are nonzero
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_1{} / ... / num_n{}>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number.cpp div
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, add, sub, mul, mod, pow
    template<typename head, typename... tail>
    using div = typename detail::_div<head, tail...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/fold.hpp>

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _div
        {};

        template<int_ x>
        struct _div<number<x>> :
            number<x>
        {};

        template<int_ x, int_ y>
        struct _div<number<x>, number<y>> :
            number<x / y>
        {};

        template<int_ x>
        struct _div<number<x>, number<0>>
        {};

        template<int_ x, int_ y, int_... tail>
        struct _div<number<x>, number<y>, number<tail>...> :
            _fold<
                numbers<y, tail...>, number<x>, lambda<div>,
                number<0>, number<sizeof...(tail) + 1>
            >
        {};
    }
}

#endif
