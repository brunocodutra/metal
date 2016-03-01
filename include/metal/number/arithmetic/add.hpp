// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_ARITHMETIC_ADD_HPP
#define METAL_NUMBER_ARITHMETIC_ADD_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct add;
    }

    /// \ingroup arithmetic
    /// Computes the addition of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, ..., valn`
    /// \code
    ///     metal::add<val1, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If all \values in `[val1, ..., valn]` are \numbers,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct metal::add<val1, ..., valn> :
    ///             metal::number<
    ///                 decltype(val1::value + ... + valn::value),
    ///                 val1::value + ... + valn::value
    ///             >
    ///         {};
    ///     \endcode
    ///     otherwise, equivalent to `metal::nothing`
    ///
    /// Example
    /// -------
    /// \snippet number/arithmetic.cpp add
    ///
    /// See Also
    /// --------
    /// \see number, inc, dec, neg, sub, mul, div, mod, pow
    template<typename... nums>
    using add = detail::add<nums...>;

    /// \ingroup arithmetic
    /// Eager adaptor for \ref add.
    template<typename... nums>
    using add_t = typename metal::add<nums...>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct add
        {};

        template<typename tx, tx vx>
        struct add<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct add<number<tx, vx>, number<ty, vy>, nums...> :
            add<number<decltype(vx + vy), vx + vy>, nums...>
        {};
    }
}

#endif
