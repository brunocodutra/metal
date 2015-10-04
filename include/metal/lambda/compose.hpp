// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_COMPOSE_HPP
#define METAL_LAMBDA_COMPOSE_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename... lbds>
    struct compose
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref compose.
    template<typename... lbds>
    using compose_t = typename metal::compose<lbds...>::type;
}

#include <metal/lambda/identity.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/eval.hpp>

namespace metal
{
    template<typename head, typename... tail>
    struct compose<head, tail...> :
        compose<head, compose_t<tail...>>
    {};

    template<typename x, typename y>
    struct compose<x, y>
    {
        template<typename... args>
        using _ = bind_t<y, eval<bind_t<x, args>>...>;

        using type = lambda<_>;
    };

    template<
        typename x,
        template<template<typename...> class> class lambda,
        template<typename...> class y
    >
    struct compose<x, lambda<y>>
    {
        template<typename... args>
        using _ = y<eval<bind_t<x, args...>>>;

        using type = lambda<_>;
    };

    template<
        typename x,
        template<template<typename...> class> class lambda
    >
    struct compose<x, lambda<identity>>
    {
        template<typename... args>
        using _ = eval<bind_t<x, args...>>;

        using type = lambda<_>;
    };

    template<typename lbd>
    struct compose<lbd>
    {
        using type = lbd;
    };
}

#endif
