// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/lambda/arg.hpp>
#include <metal/expression/eval.hpp>
#include <metal/list/at.hpp>
#include <metal/list/flatten.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/extract.hpp>

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
        template<template<typename...> class expr>
        struct lift
        {
            template<typename>
            struct forward;

            template<template<typename...> class list, typename... args>
            struct forward<list<args...>> :
                    eval<expr, args...>
            {};

            template<typename... opts>
            using type = forward<flatten_t<list<from_just<opts>...>>>;
        };

        template<typename...>
        struct apply_impl;

        template<typename val, typename... args>
        struct apply_impl<val, args...>
        {
            using type = val;
        };

        template<std::size_t n, typename... args>
        struct apply_impl<arg<n>, args...> :
                conditional<
                    boolean<n <= sizeof...(args)>,
                    at<list<args...>, number<std::size_t, n - 1>>
                >
        {};

        template<typename... args>
        struct apply_impl<arg<0U>, args...> :
                list<args...>
        {};

        template<
            template<typename...> class expr,
            typename... params,
            typename... args
        >
        struct apply_impl<expr<params...>, args...> :
                eval<
                    lift<expr>::template type,
                    apply_impl<params, args...>...
                >
        {};

        template<template<typename...> class expr, typename... args>
        struct apply_impl<expr<arg<0U>>, args...> :
                eval<expr, args...>
        {};
    }

    template<typename lbd, typename... args>
    struct apply<lbd, args...> :
            detail::apply_impl<lbd, args...>
    {};

    template<typename... args>
    struct apply<arg<0U>, args...>
    {};
}

#endif
