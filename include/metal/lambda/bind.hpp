// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/core/voider.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct bind;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref bind.
    template<typename... args>
    using bind_t = typename metal::bind<args...>::type;

    namespace detail
    {
        template<template<typename...> class, typename, typename = void>
        struct wrap
        {};

        template<
            template<typename...> class expr,
            template<typename...> class list,
            typename... args
        >
        struct wrap<expr, list<args...>, voider_t<expr<args...>>>
        {
            using type = expr<args...>;
        };

        template<typename val>
        struct quasiquote;

        template<typename val>
        using quasiquote_t = typename quasiquote<val>::type;

        template<typename val>
        struct quasiquote
        {
            using type = val;
        };

        template<template<typename...> class expr, typename... params>
        struct quasiquote<expr<params...>>
        {
            template<typename... args>
            struct _ :
                    detail::wrap<lambda<expr>::template type, _<args...>>
            {};

            using type = _<quasiquote_t<params>...>;
        };

        template<
            template<template<typename...> class> class lambda,
            template<typename...> class expr
        >
        struct quasiquote<lambda<expr>> :
                quote<lambda<expr>>
        {};
    }

    template<typename lbd, typename... args>
    struct bind<lbd, args...> :
            apply<detail::quasiquote_t<lbd>, args...>
    {};

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class expr,
        typename... args
    >
    struct bind<lambda<expr>, args...> :
            detail::wrap<metal::lambda<expr>::template type, list<args...>>
    {};
}

#endif
