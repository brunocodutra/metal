// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/core/voider.hpp>
#include <metal/list/at.hpp>
#include <metal/list/flatten.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/conditional.hpp>
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

        template<
            template<typename...> class expr,
            template<typename...> class list,
            typename... args
        >
        struct eval<expr, list<args...>, voider_t<expr<args...>>> :
                maybe<expr<args...>>
        {};

        template<template<typename...> class expr>
        struct lift
        {
            template<typename... opts>
            using type = eval<
                lambda<expr>::template type,
                flatten_t<list<from_just<opts>...>>
            >;
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
                    at<apply_impl<arg<n>, args...>, number<std::size_t, n>>
                >
        {};

        template<typename... args>
        struct apply_impl<arg<0U>, args...> :
                list<args...>
        {};

        template<template<typename...> class expr, typename... args>
        struct apply_impl<expr<>, args...> :
                maybe<expr<>>
        {};

        template<
            template<typename...> class expr,
            typename... params,
            typename... args
        >
        struct apply_impl<expr<params...>, args...> :
                eval<
                    lift<expr>::template type,
                    list<apply_impl<params, args...>...>
                >
        {};

        template<
            template<template<typename...> class> class lambda,
            template<typename...> class expr,
            typename... args
        >
        struct apply_impl<lambda<expr>, args...> :
                eval<metal::lambda<expr>::template type, list<args...>>
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
