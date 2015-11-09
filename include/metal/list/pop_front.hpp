// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_POP_FRONT_HPP
#define METAL_LIST_POP_FRONT_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list>
    struct pop_front
    {};

    /// \ingroup list
    /// Eager adaptor for \ref pop_front.
    template<typename list>
    using pop_front_t = typename metal::pop_front<list>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/list.hpp>

namespace metal
{
    template<template<typename...> class list, typename head, typename... tail>
    struct pop_front<list<head, tail...>> :
        copy<list<head, tail...>, metal::list<tail...>>
    {};
}

#endif
