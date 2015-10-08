// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_FLATTEN_HPP
#define METAL_LIST_FLATTEN_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct flatten
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref flatten.
    template<typename list>
    using flatten_t = typename metal::flatten<list>::type;
}

#include <metal/list/join.hpp>
#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    namespace detail
    {
        template<typename>
        struct flatten_impl;

        template<typename list>
        using flatten_impl_t = typename flatten_impl<list>::type;

        template<template<typename...> class list, typename... vals>
        struct flatten_impl<list<vals...>> :
            join<flatten_impl_t<list<vals>>...>
        {};

        template<
            template<typename...> class outer,
            template<typename...> class inner,
            typename... vals
        >
        struct flatten_impl<outer<inner<vals...>>> :
            flatten_impl<outer<vals...>>
        {};

        template<template<typename...> class list, typename val>
        struct flatten_impl<list<val>>
        {
            using type = list<val>;
        };

        template<template<typename...> class list>
        struct flatten_impl<list<>>
        {
            using type = list<>;
        };
    }

    template<template<typename...> class list, typename... vals>
    struct flatten<list<vals...>> :
        detail::flatten_impl_t<defer<lambda<list>, vals...>>
    {};
}

#endif
