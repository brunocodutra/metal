// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_SUB_HPP
#define METAL_NUMBER_SUB_HPP

#include <metal/config.hpp>

#include <metal/detail/sfinae.hpp>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _sub;
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
    using sub = detail::call<detail::_sub<nums...>::template type>;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/value/fold_left.hpp>

#include <initializer_list>

namespace metal {
    /// \cond
    namespace detail {
        template<typename... nums>
        struct _sub
        {};

#if defined(METAL_WORKAROUND)
        template<typename x, typename y>
        using sub_impl = number<x::value - y::value>;

        template<int_... ns>
        struct _sub<number<ns>...>
        {
            template<typename... _>
            using type = fold_left<lambda<sub_impl>, number<ns>..., _...>;
        };
#else
        template<typename... _>
        constexpr int_ sub_impl(int_ head, _... tail) {
            return void(std::initializer_list<int_>{(head -= tail)...}), head;
        }

        template<int_... ns>
        struct _sub<number<ns>...>
        {
            template<typename... _>
            using type = number<sub_impl((void(sizeof...(_)), ns)...)>;
        };
#endif
    }
    /// \endcond
}

#endif
