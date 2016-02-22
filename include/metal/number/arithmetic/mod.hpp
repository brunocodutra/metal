// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_MOD_HPP
#define METAL_NUMBER_ARITHMETIC_MOD_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct mod;
    }

    /// \ingroup arithmetic
    /// Computes the remainder of the division of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, val2, ..., valn`
    /// \code
    ///     using result = metal::mod<val1, val2, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val1` is a \number
    ///     and all \values in `[val2, ..., valn]` are nonzero \numbers,
    ///     then equivalent to
    ///     \code
    ///         struct result :
    ///             metal::number<
    ///                 decltype(val1::value % ... % valn::value),
    ///                 val1::value % ... % valn::value
    ///             >
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp mod
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, add, sub, mul, mod, pow
    template<typename... nums>
    using mod = detail::mod<nums...>;

    /// \ingroup arithmetic
    /// Eager adaptor for \ref mod.
    template<typename... nums>
    using mod_t = typename metal::mod<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct mod
        {};

        template<typename tx, tx vx>
        struct mod<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct mod<number<tx, vx>, number<ty, vy>, nums...> :
            mod<number<decltype(vx % vy), vx % vy>, nums...>
        {};

        template<typename tx, tx vx, typename ty, typename... nums>
        struct mod<number<tx, vx>, number<ty, ty(0)>, nums...>
        {};
    }
}

#endif
