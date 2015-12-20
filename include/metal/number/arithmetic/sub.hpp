// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_SUB_HPP
#define METAL_NUMBER_ARITHMETIC_SUB_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct sub;
    }

    /// \ingroup arithmetic
    /// Computes the subtraction of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, ..., valn`
    /// \code
    ///     using result = metal::sub<val1, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If all \values in `[val1, ..., valn]` are \numbers,
    ///     then equivalent to
    ///     \code
    ///         using result = metal::number<
    ///             decltype(val1::value - ... - valn::value),
    ///             val1::value - ... - valn::value
    ///         >;
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         using result = metal::nothing;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp sub
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, add, mul, div, mod
    template<typename... nums>
    using sub = detail::sub<nums...>;

    /// \ingroup arithmetic
    /// Eager adaptor for \ref sub.
    template<typename... nums>
    using sub_t = typename metal::sub<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct sub
        {};

        template<typename tx, tx vx>
        struct sub<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct sub<number<tx, vx>, number<ty, vy>, nums...> :
            sub<number<decltype(vx - vy), vx - vy>, nums...>
        {};
    }
}

#endif
