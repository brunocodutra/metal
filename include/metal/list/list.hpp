// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_LIST_HPP
#define METAL_LIST_LIST_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename... vals>
    struct list;

    /// \ingroup sequece
    /// \brief ...
    template<typename list>
    struct is_list;

    /// \ingroup list
    /// \brief Eager adaptor for \ref is_list.
    template<typename list>
    using is_list_t = typename metal::is_list<list>::type;

    template<typename... vals>
    struct list
    {
        using type = list;
    };

    template<typename>
    struct is_list :
            boolean<false>
    {};

    template<template<typename...> class list, typename... vals>
    struct is_list<list<vals...>> :
            boolean<true>
    {};
}

#endif
