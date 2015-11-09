// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_PUSH_BACK_HPP
#define METAL_LIST_PUSH_BACK_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list, typename val>
    struct push_back
    {};

    /// \ingroup list
    /// Eager adaptor for \ref push_back.
    template<typename list, typename val>
    using push_back_t = typename metal::push_back<list, val>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/list.hpp>

namespace metal
{
    template<template<typename...> class list, typename... vals, typename val>
    struct push_back<list<vals...>, val> :
        copy<list<vals...>, metal::list<vals..., val>>
    {};
}

#endif
