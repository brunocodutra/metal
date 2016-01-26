// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... vals>
        struct invoke;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename... vals>
    using invoke = detail::invoke<lbd, vals...>;

    /// \ingroup lambda
    /// Eager adaptor for \ref invoke.
    template<typename lbd, typename... vals>
    using invoke_t = typename metal::invoke<lbd, vals...>::type;
}

#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/optional.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<
            template<typename...> class expr, typename... args,
            typename ret = optional<expr<typename args::type...>>
        >
        ret invoke_impl(list<args...>*);

        template<template<typename...> class>
        nothing invoke_impl(...);

        template<typename val, typename... vals>
        struct invoke :
            just<val>
        {};

        template<template<typename...> class expr, typename... vals>
        struct invoke<lambda<expr>, vals...> :
            decltype(invoke_impl<expr>(declptr<list<just<vals>...>>()))
        {};

        template<
            template<typename...> class expr,
            typename... params,
            typename... vals
        >
        struct invoke<expr<params...>, vals...> :
            decltype(
                invoke_impl<expr>(
                    declptr<list<invoke<params, vals...>...>>()
                )
            )
        {};

        template<std::size_t n, typename... vals>
        struct invoke<arg<n>, vals...> :
            at<invoke<arg<n>, vals...>, number<std::size_t, n>>
        {};

        template<typename x, typename y, typename z, typename... tail>
        struct invoke<arg<3U>, x, y, z, tail...> :
            just<z>
        {};

        template<typename x, typename y, typename... tail>
        struct invoke<arg<2U>, x, y, tail...> :
            just<y>
        {};

        template<typename x, typename... tail>
        struct invoke<arg<1U>, x, tail...> :
            just<x>
        {};

        template<typename... vals>
        struct invoke<arg<0U>, vals...>
        {};
    }
}

#endif
