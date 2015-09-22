// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/just.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct bind
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref bind.
    template<typename... args>
    using bind_t = typename metal::bind<args...>::type;

    namespace detail
    {
        template<typename val>
        struct quasiquote
        {
            using type = val;
        };

        template<typename... args>
        using quasiquote_t = typename quasiquote<args...>::type;

        template<
            template<template<typename...> class> class lambda,
            template<typename...> class expr
        >
        struct quasiquote<lambda<expr>>
        {
            template<typename... args>
            using _ = just<expr<args...>>;

            using type = metal::lambda<_>;
        };

        template<template<typename...> class expr, typename... params>
        struct quasiquote<expr<params...>>
        {
            template<typename... args>
            struct _ :
                just<expr<args...>>
            {};

            using type = _<quasiquote_t<params>...>;
        };
    }

    template<typename lbd, typename... args>
    struct bind<lbd, args...> :
        invoke<detail::quasiquote_t<lbd>, args...>
    {};

    template<
        template<template<typename...> class> class lambda,
        typename... args
    >
    struct bind<lambda<bind>, args...> :
        just<bind<args...>>
    {};
}

#endif
