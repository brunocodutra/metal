// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct invoke
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref invoke.
    template<typename... args>
    using invoke_t = typename invoke<args...>::type;
}

#include <metal/lambda/bind.hpp>
#include <metal/optional/eval.hpp>
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
            typename bound = expr<typename args::type...>,
            typename ret = eval<bound>
        >
        just<ret> invoke_impl(list<args...>*, int bound::* = 0);

        template<template<typename...> class expr>
        nothing invoke_impl(...);
    }

    template<typename val, typename... args>
    struct invoke<val, args...> :
        bind<val, args...>
    {};

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class expr,
        typename... args
    >
    struct invoke<lambda<expr>, args...> :
        decltype(detail::invoke_impl<expr>(
            static_cast<invoke<just<args>...>*>(0)
        ))
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct invoke<expr<params...>, args...> :
        decltype(detail::invoke_impl<expr>(
            static_cast<invoke<invoke<params, args...>...>*>(0)
        ))
    {};
}

#endif
