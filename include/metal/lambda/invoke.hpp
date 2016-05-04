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
    /// Eager adaptor for metal::invoke.
    template<typename lbd, typename... args>
    using invoke_t = typename metal::invoke<lbd, args...>::type;
}

#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/optional.hpp>

#include <metal/detail/declptr.hpp>
#include <metal/detail/void.hpp>

namespace metal
{
    namespace detail
    {
#if defined(_MSC_VER)
        nothing invoke_impl_(...);

        template<
            template<typename...> class expr, typename... args,
            typename ret = expr<typename args::type...>
        >
        optional<ret> invoke_impl_(lambda<expr>*, list<args...>*);

        template<typename lbd, typename args>
        struct invoke_impl :
            decltype(invoke_impl_(declptr<lbd>(), declptr<args>()))
        {};
#else
        template<typename, typename, typename = void>
        struct invoke_impl
        {};

        template<template<typename...> class expr, typename... args>
        struct invoke_impl<lambda<expr>, list<args...>,
            void_t<expr<typename args::type...>>
        > :
            optional<expr<typename args::type...>>
        {};
#endif

        template<typename val, typename... args>
        struct invoke
        {
            using type = val;
        };

        template<template<typename...> class expr, typename... args>
        struct invoke<lambda<expr>, args...> :
            invoke_impl<lambda<expr>, list<just<args>...>>
        {};

        template<
            template<typename...> class expr,
            typename... params,
            typename... args
        >
        struct invoke<expr<params...>, args...> :
            invoke_impl<lambda<expr>, list<invoke<params, args...>...>>
        {};

        template<std::size_t n, typename... args>
        struct invoke<arg<n>, args...> :
            at<list<arg<n>, args...>, number<std::size_t, n>>
        {};

        template<
            typename h1, typename h2, typename h3, typename h4, typename h5,
            typename... tail
        >
        struct invoke<_5, h1, h2, h3, h4, h5, tail...>
        {
            using type = h5;
        };

        template<
            typename h1, typename h2, typename h3, typename h4,
            typename... tail
        >
        struct invoke<_4, h1, h2, h3, h4, tail...>
        {
            using type = h4;
        };

        template<typename h1, typename h2, typename h3, typename... tail>
        struct invoke<_3, h1, h2, h3, tail...>
        {
            using type = h3;
        };

        template<typename h1, typename h2, typename... tail>
        struct invoke<_2, h1, h2, tail...>
        {
            using type = h2;
        };

        template<typename h1, typename... tail>
        struct invoke<_1, h1, tail...>
        {
            using type = h1;
        };

        template<typename... args>
        struct invoke<arg<0U>, args...>
        {};
    }
}

#endif
