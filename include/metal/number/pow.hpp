// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_POW_HPP
#define METAL_NUMBER_POW_HPP

#include <metal/config.hpp>

#include <metal/detail/sfinae.hpp>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _pow;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic exponentiation of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::pow<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \pre: `metal::pow<num_0, ..., num_m-1> != metal::number<0>` for all
    /// negative `num_m`
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} ** ... ** num_n-1{}>;
    ///     \endcode
    ///     Where `x**y` stands for `x` raised to the power of `y`
    ///     \warning{
    ///         `x**y` is always null for `y < 0` and `|x| > 1`
    ///         due to inherent limitations of integer arithmetic.
    ///     }
    ///
    /// ### Example
    /// \snippet number.cpp pow
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, add, sub, mul, div, mod
    template<typename... nums>
    using pow = detail::call<detail::_pow<nums...>::template type>;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/value/fold_left.hpp>

namespace metal {
    /// \cond
    namespace detail {
        template<typename base, typename exp, typename ret = number<1>>
        struct _pow_impl
        {};

        template<int_ b, int_ e, int_ r>
        struct _pow_impl<number<b>, number<e>, number<r>> :
            _pow_impl<number<b*b>, number<e/2>, number<(e%2 ? b*r : r)>>
        {};

        template<int_ b, int_ r>
        struct _pow_impl<number<b>, number<0>, number<r>> :
            number<1>
        {};

        template<int_ b, int_ r>
        struct _pow_impl<number<b>, number<1>, number<r>> :
            number<b*r>
        {};

        template<int_ b, int_ r>
        struct _pow_impl<number<b>, number<-1>, number<r>> :
            number<1/(b*r)>
        {};

        template<int_ r>
        struct _pow_impl<number<0>, number<-1>, number<r>>
        {};

        template<typename x, typename y>
        using pow_impl = typename _pow_impl<x, y>::type;

        template<typename... nums>
        struct _pow
        {};

        template<int_... ns>
        struct _pow<number<ns>...>
        {
            template<typename... _>
            using type = fold_left<lambda<pow_impl>, number<ns>..., _...>;
        };
    }
    /// \endcond
}

#endif
