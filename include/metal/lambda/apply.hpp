// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/lambda/arg.hpp>
#include <metal/lambda/protect.hpp>
#include <metal/optional/maybe.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

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
        template<std::size_t...>
        struct enumeration
        {
            using type = enumeration;
        };

        template<typename, typename>
        struct merge;

        template<std::size_t... l, std::size_t... u>
        struct merge<enumeration<l...>, enumeration<u...>> :
                enumeration<l..., sizeof...(l) + u...>
        {};

        template<std::size_t n>
        struct enumerate;

        template<std::size_t n>
        using enumerate_t = typename enumerate<n>::type;

        template<std::size_t n>
        struct enumerate :
                merge<enumerate_t<n/2>, enumerate_t<n - n/2>>
        {};

        template<>
        struct enumerate<0U> :
                enumeration<>
        {};

        template<>
        struct enumerate<1U> :
                enumeration<0U>
        {};

        template<std::size_t, typename value>
        struct item
        {};

        template<typename, typename...>
        struct hash;

        template<std::size_t... ids, typename... args>
        struct hash<enumeration<ids...>, args...> :
                item<ids, args>...
        {};

        template<std::size_t n, typename... args>
        struct select
        {
        private:
            static hash<enumerate_t<sizeof...(args)>, args...>* make_hash();

            template<typename value>
            static just<value> impl(item<n - 1, value>*);
            static nothing impl(...);

        public:
            using type = decltype(impl(make_hash()));
        };

        template<typename>
        struct eval;

        template<template<typename...> class expr, typename... args>
        struct eval<expr<args...>>
        {
        private:
            static expr<args...>* forward();

            template<typename... a>
            static maybe<expr<typename a::type...>> impl(expr<a...>*);
            static nothing impl(...);

        public:
            using type = decltype(impl(forward()));
        };

        template<typename... args>
        struct reduce
        {};

        template<typename value, typename... args>
        struct reduce<value, args...>
        {
            using type = value;
        };

        template<typename... args>
        using reduce_t = typename reduce<args...>::type;

        template<
            template<typename...> class expr,
            typename... params,
            typename... args
        >
        struct reduce<expr<params...>, args...> :
                eval<expr<reduce<params, args...>...>>::type
        {};

        template<std::size_t n, typename... args>
        struct reduce<arg<n>, args...> :
               select<n, args...>::type
        {};

        template<typename... args>
        struct reduce<arg<0>, args...>
        {};
    }

    template<typename value, typename... args>
    struct apply
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct apply<expr<params...>, args...> :
            detail::reduce<expr<params...>, args...>
    {};

    template<std::size_t n, typename... args>
    struct apply<arg<n>, args...> :
            detail::reduce<arg<n>, args...>
    {};

    template<typename val, typename... args>
    struct apply<detail::atom<val>, args...> :
            apply<val, args...>
    {};
}

#endif
