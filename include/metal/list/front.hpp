// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_FRONT_HPP
#define METAL_LIST_FRONT_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct front;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using front = detail::front<list>;

    /// \ingroup list
    /// Eager adaptor for \ref front.
    template<typename list>
    using front_t = typename metal::front<list>::type;

    namespace detail
    {
        template<typename list>
        struct front
        {};

        template<template<typename...> class list, typename head, typename... tail>
        struct front<list<head, tail...>>
        {
            using type = head;
        };
    }
}

#endif
