// Copyright Bruno Dutra 2015-2018
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_SUB_HPP
#define METAL_NUMBER_SUB_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename x, typename y>
        struct _sub;

        template<typename x, typename y>
        using sub = typename _sub<x, y>::type;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic subtraction of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::sub<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} - ... - num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp sub
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, add, mul, div, mod, pow
    template<typename... nums>
    using sub = fold_left<lambda<detail::sub>, nums..., number<0>>;

    /// \cond
    namespace detail {
        template<typename x, typename y>
        struct _sub {};

        template<int_ x, int_ y>
        struct _sub<number<x>, number<y>> {
            using type = number<x - y>;
        };
    }
    /// \endcond
}

#endif
