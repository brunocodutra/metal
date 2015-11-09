// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_EMPTY_HPP
#define METAL_LIST_EMPTY_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list>
    struct empty
    {};

    /// \ingroup list
    /// Eager adaptor for \ref empty.
    template<typename list>
    using empty_t = typename metal::empty<list>::type;
}

#include <metal/list/size.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    template<template<typename...> class list, typename... vals>
    struct empty<list<vals...>> :
        not_<size_t<list<vals...>>>
    {};
}

#endif
