// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_QUASIQUOTE_HPP
#define METAL_LAMBDA_QUASIQUOTE_HPP

#include <metal/lambda/apply.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/core/voider.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename val>
    struct quasiquote;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref quasiquote.
    template<typename val>
    using quasiquote_t = typename quasiquote<val>::type;

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
    }

    template<typename val>
    struct quasiquote
    {
        using type = val;
    };

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class expr
    >
    struct quasiquote<lambda<expr>>
    {
        template<typename... args>
        struct _ :
                detail::wrap<metal::lambda<expr>::template type, _<args...>>
        {};

        using type = _<_0>;
    };

    template<template<typename...> class expr, typename... params>
    struct quasiquote<expr<params...>> :
            quasiquote<lambda<expr>>
    {
        using type =
            typename quasiquote<lambda<expr>>::template
                _<quasiquote_t<params>...>;
    };
}

#endif
