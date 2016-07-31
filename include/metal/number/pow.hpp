// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_POW_HPP
#define METAL_NUMBER_POW_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _pow;
    }

    /// \ingroup number
    /// Computes the arithmetic exponentiation of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \numbers `num_1, ..., num_n`
    /// \code
    ///     using result = metal::pow<num_1, ..., num_n>;
    /// \endcode
    ///
    /// \pre: `num_1{} ** ... ** num_m-1{}` is nonzero for all
    /// negative `num_m`
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<
    ///             decltype(num_1{} ** ... ** num_n{}),
    ///             num_1{} ** ... ** num_n{}
    ///         >;
    ///     \endcode
    ///     \note{
    ///         Borrowing from Fortran, `x ** y` should be understood as
    ///         `x` raised to the power of `y`.
    ///     }
    ///     \danger{
    ///         `x ** y` is always null for `y < 0` and `|x| > 1`
    ///         due to inherent limitations of integer arithmetics.
    ///     }
    ///
    /// Example
    /// -------
    /// \snippet number.cpp pow
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, add, sub, mul, div, mod
    template<typename head, typename... tail>
    using pow = typename detail::_pow<head, tail...>::type;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>
#include <metal/list/fold.hpp>

namespace metal
{
    namespace detail
    {
        template<typename base, typename exp, typename ret = int_<1>>
        struct _pow_impl
        {};

        template<
            typename base, base b,
            typename exp, exp e,
            typename ret, ret r
        >
        struct _pow_impl<number<base, b>, number<exp, e>, number<ret, r>> :
            _pow_impl<
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
        struct _pow_impl<
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
        struct _pow_impl<
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
        struct _pow_impl<
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
        struct _pow_impl<
            number<base, static_cast<base>(0)>,
            number<exp, static_cast<exp>(-1)>,
            number<ret, r>
        >
        {};

        template<typename head, typename... tail>
        struct _pow
        {};

        template<typename tx, tx vx>
        struct _pow<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct _pow<number<tx, vx>, number<ty, vy>> :
            _pow_impl<number<tx, vx>, number<ty, vy>>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct _pow<number<tx, vx>, number<ty, vy>, nums...> :
            _fold<
                list<number<ty, vy>, nums...>,
                number<tx, vx>, lambda<pow>,
                size_t<0>, size_t<sizeof...(nums) + 1>
            >
        {};
    }
}

#endif
