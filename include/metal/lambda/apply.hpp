// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/lambda/arg.hpp>
#include <metal/expression/eval.hpp>
#include <metal/optional/maybe.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>
#include <metal/optional/extract.hpp>
#include <metal/sequence/list.hpp>
#include <metal/sequence/enumerate.hpp>
#include <metal/sequence/size.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename lbd, typename... args>
    struct apply;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref apply.
    template<typename lbd, typename... args>
    using apply_t = typename metal::apply<lbd, args...>::type;

    namespace detail
    {
        template<typename, typename>
        struct item
        {};

        template<typename, typename>
        struct hash;

        template<
            template<typename...> class list,
            typename... keys, typename... vals
        >
        struct hash<list<keys...>, list<vals...>> :
                item<keys, vals>...
        {};

        template<std::size_t n, typename... args>
        struct select
        {
        private:
            template<typename val>
            static just<val> impl(item<number<std::size_t, n - 1>, val>*);
            static nothing impl(...);

            template<typename seq>
            static hash<enumerate_t<size_t<seq>>, seq>* make_hash();

        public:
            using type = decltype(impl(make_hash<list<args...>>()));
        };

        template<template<typename...> class expr>
        struct lift
        {
            template<typename... opts>
            using type = expr<extract<opts>...>;
        };
    }

    template<typename lbd, typename... args>
    struct apply :
            just<lbd>
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct apply<expr<params...>, args...> :
            eval<
                detail::lift<expr>::template type,
                apply<params, args...>...
            >
    {};

    template<std::size_t n, typename... args>
    struct apply<arg<n>, args...> :
           detail::select<n, args...>::type
    {};

    template<typename... args>
    struct apply<arg<0U>, args...>
    {};
}

#endif
