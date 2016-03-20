// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MUL_HPP
#define METAL_NUMBER_ARITHMETIC_MUL_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct mul;
    }

    /// \ingroup arithmetic
    /// Computes the multiplication of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, ..., valn`
    /// \code
    ///     metal::mul<val1, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If all \values in `[val1, ..., valn]` are \numbers,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct mul<val1, ..., valn> :
    ///             number<
    ///                 decltype(val1::value * ... * valn::value),
    ///                 val1::value * ... * valn::value
    ///             >
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp mul
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, add, sub, div, mod, pow
    template<typename... nums>
    using mul = detail::mul<nums...>;

    /// \ingroup arithmetic
    /// Eager adaptor for \ref mul.
    template<typename... nums>
    using mul_t = typename metal::mul<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/reduce.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct mul
        {};

        template<typename tx, tx vx>
        struct mul<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct mul<number<tx, vx>, number<ty, vy>> :
            number<decltype(vx * vy), vx * vy>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct mul<number<tx, vx>, number<ty, vy>, nums...> :
            reduce<list<number<tx, vx>, number<ty, vy>, nums...>, lambda<mul>>
        {};
    }
}

#endif
