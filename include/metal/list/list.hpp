// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_LIST_HPP
#define METAL_LIST_LIST_HPP

namespace metal
{
    namespace detail
    {
        template<typename... vals>
        struct list;

        template<typename list>
        struct is_list;
    }

    /// \ingroup list
    /// ...
    template<typename... vals>
    using list = detail::list<vals...>;

    /// \ingroup list
    /// ...
    template<typename list>
    using is_list = detail::is_list<list>;

    /// \ingroup list
    /// Eager adaptor for \ref is_list.
    template<typename list>
    using is_list_t = typename metal::is_list<list>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... vals>
        struct list
        {
            using type = list;
        };

        template<typename list>
        struct is_list :
            boolean<false>
        {};

        template<template<typename...> class list, typename... vals>
        struct is_list<list<vals...>> :
            boolean<true>
        {};
    }
}

#endif
