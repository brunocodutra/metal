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
#include <metal/sequence/list.hpp>
#include <metal/sequence/enumerate.hpp>
#include <metal/sequence/size.hpp>

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename lambda, typename... args>
    struct apply;

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref apply.
    template<typename lambda, typename... args>
    using apply_t = typename metal::apply<lambda, args...>::type;

    /// \ingroup lambda
    /// \brief ...
    template<typename lambda, typename... args>
    struct is_applicable :
            is_just<apply<lambda, args...>>
    {};

    /// \ingroup traits
    /// \brief Eager adaptor for \ref is_applicable.
    template<typename lambda, typename... args>
    using is_applicable_t =
        typename metal::is_applicable<lambda, args...>::type;

    namespace detail
    {
        template<std::size_t, typename>
        struct item
        {};

        template<typename, typename>
        struct hash;

        template<
            template<typename...> class list,
            typename... keys, typename... values
        >
        struct hash<list<keys...>, list<values...>> :
                item<keys::value, values>...
        {};

        template<std::size_t n, typename... args>
        struct select
        {
        private:
            template<typename value>
            static just<value> impl(item<n - 1, value>*);
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
            using type = expr<typename opts::type...>;
        };
    }

    template<typename lambda, typename... args>
    struct apply :
            just<lambda>
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
