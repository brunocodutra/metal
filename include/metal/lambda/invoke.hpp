// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename... args>
        struct invoke;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename... args>
    using invoke = detail::invoke<lbd, args...>;

    /// \ingroup lambda
    /// Eager adaptor for \ref invoke.
    template<typename lbd, typename... args>
    using invoke_t = typename metal::invoke<lbd, args...>::type;
}

#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
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
            typename ret = expr<typename args::type...>
        >
        optional<ret> invoke_impl(list<args...>*);

        template<template<typename...> class>
        nothing invoke_impl(...);

        template<typename val, typename... args>
        struct invoke
        {
            using type = val;
        };

        template<template<typename...> class expr, typename... args>
        struct invoke<lambda<expr>, args...> :
            decltype(invoke_impl<expr>(declptr<list<quote_t<args>...>>()))
        {};

        template<
            template<typename...> class expr,
            typename... params,
            typename... args
        >
        struct invoke<expr<params...>, args...> :
            decltype(
                invoke_impl<expr>(
                    declptr<list<invoke<params, args...>...>>()
                )
            )
        {};

        template<std::size_t n, typename... args>
        struct invoke<arg<n>, args...> :
            at<invoke<arg<n>, args...>, number<std::size_t, n>>
        {};

        template<typename x, typename y, typename z, typename... tail>
        struct invoke<arg<3U>, x, y, z, tail...>
        {
            using type = z;
        };

        template<typename x, typename y, typename... tail>
        struct invoke<arg<2U>, x, y, tail...>
        {
            using type = y;
        };

        template<typename x, typename... tail>
        struct invoke<arg<1U>, x, tail...>
        {
            using type = x;
        };

        template<typename... args>
        struct invoke<arg<0U>, args...>
        {};
    }
}

#endif
