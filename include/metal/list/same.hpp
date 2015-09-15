// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SAME_HPP
#define METAL_LIST_SAME_HPP

#include <metal/core/are_same.hpp>

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct same
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref same.
    template<typename list>
    using same_t = typename same<list>::type;

    template<template<typename...> class list, typename... vals>
    struct same<list<vals...>> :
        are_same<vals...>
    {};
}

#endif
