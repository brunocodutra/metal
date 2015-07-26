// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_APPLY_HPP
#define METAL_FUNCTIONAL_APPLY_HPP

#include <metal/functional/arg.hpp>
#include <metal/functional/just.hpp>
#include <metal/functional/maybe.hpp>
#include <metal/functional/nothing.hpp>
#include <metal/functional/protect.hpp>

namespace metal
{
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

        template<typename... args>
        hash<enumerate_t<sizeof...(args)>, args...>* make_hash();

        template<std::size_t n, typename value>
        just<value> fetch(item<n, value>*);
        template<std::size_t>
        nothing fetch(...);

        template<template<typename...> class expr, typename... args>
        maybe<expr<typename args::type...>> eval(int);
        template<template<typename...> class, typename...>
        nothing eval(...);

        template<typename value, typename... args>
        struct reduce
        {
            using type = value;
        };

        template<typename value, typename... args>
        using reduce_t = typename reduce<value, args...>::type;

        template<
            template<typename...> class expr,
            typename... params,
            typename... args
        >
        struct reduce<expr<params...>, args...> :
                decltype(eval<expr, reduce<params, args...>...>(0))
        {};

        template<
            template<typename...> class expr,
            typename... args
        >
        struct reduce<expr<>, args...> :
                decltype(eval<expr>(0))
        {};

        template<std::size_t n, typename... args>
        struct reduce<arg<n>, args...> :
               decltype(fetch<n-1>(make_hash<args...>()))
        {};

        template<typename... args>
        struct reduce<arg<0>, args...>
        {};
    }

    /// \ingroup functional
    /// \brief ...
    template<typename lambda, typename... args>
    struct apply;

    /// \ingroup functional
    /// \brief Eager adaptor for \ref apply.
    template<typename lambda, typename... args>
    using apply_t = typename metal::apply<lambda, args...>::type;

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
    struct apply<detail::lambda<val>, args...> :
            apply<val, args...>
    {};
}

#endif
