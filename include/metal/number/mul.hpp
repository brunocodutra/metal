// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_MUL_HPP
#define METAL_NUMBER_MUL_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _mul;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic multiplication of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::mul<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} * ... * num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp mul
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, add, sub, div, mod, pow
    template<typename... nums>
    using mul = detail::call<detail::_mul<nums...>::template type>;
}

#include "../lambda/lambda.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

#include <initializer_list>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _mul {};

#if defined(METAL_WORKAROUND)
        template<typename x, typename y>
        using mul_impl = number<x::value * y::value>;

        template<int_... ns>
        struct _mul<number<ns>...> {
            template<typename... _>
            using type = fold_left<lambda<mul_impl>, number<ns>..., _...>;
        };
#else
        template<typename... _>
        constexpr int_ mul_impl(int_ head, _... tail) {
            return void(std::initializer_list<int_>{(head *= tail)...}), head;
        }

        template<int_... ns>
        struct _mul<number<ns>...> {
            template<typename... _>
            using type = number<mul_impl((void(sizeof...(_)), ns)...)>;
        };
#endif
        template<>
        struct _mul<> {
            template<typename...>
            using type = number<1>;
        };
    }
    /// \endcond
}

#endif
