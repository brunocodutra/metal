// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_BIND_HPP
#define METAL_LAMBDA_BIND_HPP

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
}

#include <metal/lambda/arg.hpp>
#include <metal/lambda/identity.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

namespace metal
{
    namespace detail
    {
        template<
            template<typename...> class expr,
            template<typename...> class list,
            typename... args,
            typename ret = expr<args...>
        >
        just<ret> bind_impl(list<args...>*);

        template<template<typename...> class expr>
        nothing bind_impl(...);
    }

    template<typename val, typename... args>
    struct bind<val, args...>
    {
        using type = val;
    };

    template<std::size_t n, typename... args>
    struct bind<arg<n>, args...> :
        arg<n, args...>
    {};

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class expr,
        typename... args
    >
    struct bind<lambda<expr>, args...> :
        decltype(detail::bind_impl<expr>(static_cast<bind<args...>*>(0)))
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct bind<expr<params...>, args...> :
        bind<lift_t<lambda<identity>, lambda<expr>>, bind<params, args...>...>
    {};
}

#endif
