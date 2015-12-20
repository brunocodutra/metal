// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_DIV_HPP
#define METAL_NUMBER_ARITHMETIC_DIV_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct div;
    }

    /// \ingroup arithmetic
    /// Computes the quotient of the division of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, val2, ..., valn`
    /// \code
    ///     using result = metal::div<val1, val2, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val1` is a \number
    ///     and all \values in `[val2, ..., valn]` are nonzero \numbers,
    ///     then equivalent to
    ///     \code
    ///         using result = metal::number<
    ///             decltype(val1::value / val2::value / ... / valn::value),
    ///             val1::value / val2::value / ... / valn::value
    ///         >;
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         using result = metal::nothing;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp div
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, add, sub, mul, mod
    template<typename... nums>
    using div = detail::div<nums...>;

    /// \ingroup arithmetic
    /// Eager adaptor for \ref div.
    template<typename... nums>
    using div_t = typename metal::div<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct div
        {};

        template<typename tx, tx vx>
        struct div<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct div<number<tx, vx>, number<ty, vy>, nums...> :
            div<number<decltype(vx / vy), vx / vy>, nums...>
        {};

        template<typename tx, tx vx, typename ty, typename... nums>
        struct div<number<tx, vx>, number<ty, ty(0)>, nums...>
        {};
    }
}

#endif
