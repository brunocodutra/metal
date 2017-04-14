// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_DIV_HPP
#define METAL_NUMBER_DIV_HPP

#include <metal/config.hpp>

#include <metal/detail/sfinae.hpp>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _div;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the quotient of the arithmetic division of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::div<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \pre: All \numbers in `num_1, ..., num_n-1` are nonzero
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} / ... / num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp div
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, add, sub, mul, mod, pow
    template<typename... nums>
    using div = detail::call<detail::_div<nums...>::template type>;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/value/fold_left.hpp>

#include <initializer_list>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _div
        {};

#if defined(METAL_WORKAROUND)
        template<typename x, typename y>
        struct _div_impl
        {};

        template<int_ x, int_ y>
        struct _div_impl<number<x>, number<y>> :
            number<x / y>
        {};

        template<int_ x>
        struct _div_impl<number<x>, number<0>>
        {};

        template<typename x, typename y>
        using div_impl = typename _div_impl<x, y>::type;

        template<int_... ns>
        struct _div<number<ns>...>
        {
            template<typename... _>
            using type = fold_left<lambda<div_impl>, number<ns>..., _...>;
        };
#else
        template<typename... _>
        constexpr int_ div_impl(int_ head, _... tail) {
            return void(std::initializer_list<int_>{(head /= tail)...}), head;
        }

        template<int_... ns>
        struct _div<number<ns>...>
        {
            template<typename... _>
            using type = number<div_impl((void(sizeof...(_)), ns)...)>;
        };
#endif
    }
    /// \endcond
}

#endif
