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
    ///         struct metal::pow<val1, val2, ..., valn>
    ///             metal::number<
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
    /// Eager adaptor for \ref pow.
    template<typename... nums>
    using pow_t = typename metal::pow<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename T>
        constexpr T pow_impl(T base, T exp, T result = 1) {
            return exp == 1 ?
                base*result :
                pow_impl(base*base, exp/2, exp%2 ? result*base : result);
        }

        template<typename... nums>
        struct pow
        {};

        template<typename tx, tx vx>
        struct pow<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct pow<number<tx, vx>, number<ty, vy>, nums...> :
            conditional<
                boolean<vy < 0>,
                pow<number<decltype(vx*vy), 0>, nums...>,
                pow<
                    number<decltype(vx*vy), pow_impl<decltype(vx*vy)>(vx, vy)>,
                    nums...
                >
            >
        {};

        template<typename tx, typename ty, ty vy, typename... nums>
        struct pow<number<tx, tx(0)>, number<ty, vy>, nums...> :
            conditional<
                boolean<(vy > 0)>,
                pow<number<decltype(tx()*vy), 0>, nums...>
            >
        {};

        template<typename tx, typename ty, ty vy, typename... nums>
        struct pow<number<tx, tx(1)>, number<ty, vy>, nums...> :
            pow<number<decltype(tx()*vy), 1>, nums...>
        {};

        template<typename tx, tx vx, typename ty, typename... nums>
        struct pow<number<tx, vx>, number<ty, ty(0)>, nums...> :
            pow<number<decltype(vx*ty()), 1>, nums...>
        {};

        template<typename tx, typename ty, typename... nums>
        struct pow<number<tx, tx(0)>, number<ty, ty(0)>, nums...> :
            pow<number<decltype(tx()*ty()), 1>, nums...>
        {};

        template<typename tx, typename ty, typename... nums>
        struct pow<number<tx, tx(1)>, number<ty, ty(0)>, nums...> :
            pow<number<decltype(tx()*ty()), 1>, nums...>
        {};
    }
}

#endif
