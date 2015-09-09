// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/core/voider.hpp>
#include <metal/list/at.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/dec.hpp>
#include <metal/optional/extract.hpp>
#include <metal/optional/maybe.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename lbd, typename list>
    struct apply
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref apply.
    template<typename lbd, typename list>
    using apply_t = typename apply<lbd, list>::type;

    namespace detail
    {
        template<template<typename...> class, typename, typename = void>
        struct apply_impl
        {};

        template<
            template<typename...> class expr,
            template<typename...> class list, typename... args
        >
        struct apply_impl<expr, list<args...>, voider_t<expr<args...>>> :
                maybe<expr<args...>>
        {};

        template<template<typename...> class expr>
        struct lift
        {
            template<typename... opts>
            using type = expr<from_just<opts>...>;
        };
    }

    template<typename val, template<typename...> class list, typename... args>
    struct apply<val, list<args...>>
    {
        using type = val;
    };

    template<std::size_t n, template<typename...> class list, typename... args>
    struct apply<arg<n>, list<args...>> :
            at<list<args...>, dec_t<number<std::size_t, n>>>
    {};

    template<template<typename...> class list, typename... args>
    struct apply<arg<0U>, list<args...>>
    {};

    template<
        template<typename...> class expr,
        template<typename...> class list, typename... args
    >
    struct apply<expr<>, list<args...>> :
            maybe<expr<>>
    {};

    template<
        template<typename...> class expr, typename... params,
        template<typename...> class list, typename... args
    >
    struct apply<expr<params...>, list<args...>> :
            detail::apply_impl<
                detail::lift<expr>::template type,
                list<apply<params, list<args...>>...>
            >
    {};

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class expr,
        template<typename...> class list, typename... args
    >
    struct apply<lambda<expr>, list<args...>> :
            detail::apply_impl<metal::lambda<expr>::template type, list<args...>>
    {};

    template<
        template<template<typename...> class> class lambda,
        template<typename...> class expr,
        typename... args
    >
    struct apply<lambda<expr>, expr<args...>> :
            maybe<expr<args...>>
    {};
}

#endif
