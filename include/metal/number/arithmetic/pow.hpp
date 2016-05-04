// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_POW_HPP
#define METAL_NUMBER_ARITHMETIC_POW_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct pow;
    }

    /// \ingroup arithmetic
    /// Computes the exponentiation of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, val2, ..., valn`
    /// \code
    ///     metal::pow<val1, val2, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If all \values in `[val1, ..., valn]` are \numbers,
    ///     and `val1::value ** ... ** val{m-1}::value` is nonzero for all
    ///     nonpositive `valm`, then equivalent to
    ///     \code
    ///         template<>
    ///         struct pow<val1, val2, ..., valn> :
    ///             number<
    ///                 decltype(val1::value ** ... ** valn::value),
    ///                 val1::value ** ... ** valn::value
    ///             >
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///     \note{
    ///         Borrowing from Fortran, `x ** y` means
    ///         `x` raised to the power of `y`.
    ///     }
    ///     \danger{
    ///         Due to inherent limitations of integer arithmetics,
    ///         `x ** y` is always null for `y < 0` and `|x| > 1`.
    ///     }
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp pow
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, add, sub, mul, div, mod
    template<typename... nums>
    using pow = detail::pow<nums...>;

    /// \ingroup arithmetic
    /// Eager adaptor for metal::pow.
    template<typename... nums>
    using pow_t = typename metal::pow<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/fold.hpp>

namespace metal
{
    namespace detail
    {
        template<typename base, typename exp, typename ret = integer<1>>
        struct pow_impl
        {};

        template<
            typename base, base b,
            typename exp, exp e,
            typename ret, ret r
        >
        struct pow_impl<number<base, b>, number<exp, e>, number<ret, r>> :
            pow_impl<
                number<decltype(b*b), b*b>,
                number<decltype(e/2), e/2>,
                number<decltype(b*e*r), (e%2 ? b*r : r)>
            >
        {};

        template<
            typename base, base b,
            typename exp,
            typename ret, ret r
        >
        struct pow_impl<
            number<base, b>,
            number<exp, static_cast<exp>(0)>,
            number<ret, r>
        > :
            number<decltype(b*exp()), 1>
        {};

        template<
            typename base, base b,
            typename exp,
            typename ret, ret r
        >
        struct pow_impl<
            number<base, b>,
            number<exp, static_cast<exp>(1)>,
            number<ret, r>
        > :
            number<decltype(b*exp()), b*r>
        {};

        template<
            typename base, base b,
            typename exp,
            typename ret, ret r
        >
        struct pow_impl<
            number<base, b>,
            number<exp, static_cast<exp>(-1)>,
            number<ret, r>
        > :
            number<decltype(b*exp()), 1/(b*r)>
        {};

        template<
            typename base,
            typename exp,
            typename ret, ret r
        >
        struct pow_impl<
            number<base, static_cast<base>(0)>,
            number<exp, static_cast<exp>(-1)>,
            number<ret, r>
        >
        {};

        template<typename... nums>
        struct pow
        {};

        template<typename tx, tx vx>
        struct pow<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct pow<number<tx, vx>, number<ty, vy>> :
            pow_impl<number<tx, vx>, number<ty, vy>>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct pow<number<tx, vx>, number<ty, vy>, nums...> :
            fold<list<number<ty, vy>, nums...>, number<tx, vx>, lambda<pow>>
        {};
    }
}

#endif
