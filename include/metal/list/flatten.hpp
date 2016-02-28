// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_FLATTEN_HPP
#define METAL_LIST_FLATTEN_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct flatten;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using flatten = detail::flatten<list>;

    /// \ingroup list
    /// Eager adaptor for \ref flatten.
    template<typename list>
    using flatten_t = typename metal::flatten<list>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/list/copy.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct flatten :
            copy<list, flatten_t<metal::list<list>>>
        {};

        template<typename... vals>
        struct flatten<list<vals...>> :
            join<flatten_t<list<vals>>...>
        {};

        template<template<typename...> class inner, typename... vals>
        struct flatten<list<inner<vals...>>> :
            flatten<list<vals...>>
        {};

        template<typename val>
        struct flatten<list<val>> :
            list<val>
        {};

        template<>
        struct flatten<list<>> :
            list<>
        {};
    }
}

#endif
