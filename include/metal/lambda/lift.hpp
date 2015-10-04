// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_LIFT_HPP
#define METAL_LAMBDA_LIFT_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename... lbds>
    struct lift
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref lift.
    template<typename... lbds>
    using lift_t = typename metal::lift<lbds...>::type;
}

#include <metal/lambda/bind.hpp>
#include <metal/lambda/identity.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/optional/eval.hpp>

namespace metal
{
    template<typename head, typename... tail>
    struct lift<head, tail...> :
        lift<head, lift_t<tail...>>
    {};

    template<typename x, typename y>
    struct lift<x, y>
    {
        template<typename... args>
        using _ = bind_t<y, eval<bind_t<x, args>>...>;

        using type = lambda<_>; 
    };

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class x,
        typename y
    >
    struct lift<lambda<x>, y>
    {
        template<typename... args>
        using _ = bind_t<y, eval<x<args>>...>;

        using type = lambda<_>;
    };

    template<
        template<template<typename...> class> class lambda,
        typename y
    >
    struct lift<lambda<identity>, y>
    {
        template<typename... args>
        using _ = bind_t<y, eval<args>...>;

        using type = lambda<_>;
    };

    template<typename lbd>
    struct lift<lbd>
    {
        using type = lbd;
    };
}

#endif
