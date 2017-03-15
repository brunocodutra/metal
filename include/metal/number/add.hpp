// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_ADD_HPP
#define METAL_NUMBER_ADD_HPP

#include <metal/config.hpp>

#include <metal/detail/sfinae.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... nums>
        struct _add;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic addition of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::add<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<num_0{} + ... + num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp add
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, sub, mul, div, mod, pow
    template<typename... nums>
    using add = detail::call<detail::_add<nums...>::template type>;
}

#include <metal/number/number.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/value/fold_left.hpp>

#include <initializer_list>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename... nums>
        struct _add
        {};

#if defined(METAL_COMPAT_MODE)
        template<typename x, typename y>
        using add_impl = number<x::value + y::value>;

        template<int_... ns>
        struct _add<number<ns>...>
        {
            template<typename... _>
            using type = fold_left<lambda<add_impl>, number<ns>..., _...>;
        };
#else
        template<typename... _>
        constexpr int_ add_impl(int_ head, _... tail) {
            return void(std::initializer_list<int_>{(head += tail)...}), head;
        }

        template<int_... ns>
        struct _add<number<ns>...>
        {
            template<typename... _>
            using type = number<add_impl((void(sizeof...(_)), ns)...)>;
        };
#endif
        template<>
        struct _add<>
        {
            template<typename...>
            using type = number<0>;
        };
    }
    /// \endcond
}

#endif
