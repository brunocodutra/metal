// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MOD_HPP
#define METAL_NUMBER_MOD_HPP

namespace metal
{
    namespace detail
    {
        template<typename head, typename... tail>
        struct _mod;
    }

    /// \ingroup number
    /// Computes the remainder of the division of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, val2, ..., valn`
    /// \code
    ///     metal::mod<val1, val2, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If `val1` is a \number
    ///     and all \values in `[val2, ..., valn]` are nonzero \numbers,
    ///     then equivalent to
    ///     \code
    ///         template<>
    ///         struct mod<val1, val2, ..., valn> :
    ///             number<
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
    template<typename head, typename... tail>
    using mod = typename detail::_mod<head, tail...>::type;
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
        struct _mod
        {};

        template<typename tx, tx vx>
        struct _mod<number<tx, vx>> :
            number<tx, vx>
        {};

        template<typename tx, tx vx, typename ty, ty vy>
        struct _mod<number<tx, vx>, number<ty, vy>> :
            number<decltype(vx % vy), vx % vy>
        {};

        template<typename tx, tx vx, typename ty>
        struct _mod<number<tx, vx>, number<ty, static_cast<ty>(0)>>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... nums>
        struct _mod<number<tx, vx>, number<ty, vy>, nums...> :
            _fold<
                list<number<ty, vy>, nums...>,
                number<tx, vx>, lambda<mod>,
                size_t<0>, size_t<sizeof...(nums) + 1>
            >
        {};
    }
}

#endif
