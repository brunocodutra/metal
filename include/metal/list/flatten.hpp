// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_FLATTEN_HPP
#define METAL_LIST_FLATTEN_HPP

#include <metal/list/join.hpp>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename list>
    struct flatten
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref flatten.
    template<typename list>
    using flatten_t = typename metal::flatten<list>::type;

    template<template<typename...> class list, typename... vals>
    struct flatten<list<vals...>> :
            join_t<flatten_t<list<vals>>...>
    {};

    template<template<typename...> class list, typename... vals>
    struct flatten<list<list<vals...>>> :
            flatten<list<vals...>>
    {};

    template<template<typename...> class list, typename val>
    struct flatten<list<val>>
    {
        using type = list<val>;
    };
}

#endif
