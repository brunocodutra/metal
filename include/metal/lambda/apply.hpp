// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/core/voider.hpp>
#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/extract.hpp>
#include <metal/optional/maybe.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct apply;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref apply.
    template<typename... args>
    using apply_t = typename apply<args...>::type;

    namespace detail
    {
        template<template<typename...> class, typename, typename = void>
        struct eval
        {};

        template<template<typename...> class expr, typename... args>
        struct eval<expr, list<args...>, voider_t<expr<args...>>> :
                maybe<expr<args...>>
        {};

        template<template<typename...> class expr>
        struct lift
        {
            template<typename... opts>
            using type = expr<from_just<opts>...>;
        };
    }

    template<typename val, typename... args>
    struct apply<val, args...>
    {
        using type = val;
    };

    template<std::size_t n, typename... args>
    struct apply<arg<n>, args...> :
            at<apply<arg<n>, args...>, number<std::size_t, n>>
    {};

    template<typename... args>
    struct apply<arg<0U>, args...>
    {};

    template<template<typename...> class expr, typename... args>
    struct apply<expr<>, args...> :
            maybe<expr<>>
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct apply<expr<params...>, args...> :
            detail::eval<
                detail::lift<expr>::template type,
                list<apply<params, args...>...>
            >
    {};

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class expr,
        typename... args
    >
    struct apply<lambda<expr>, args...> :
            detail::eval<metal::lambda<expr>::template type, list<args...>>
    {};
}

#endif
