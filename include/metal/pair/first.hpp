// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_PAIR_FIRST_HPP
#define METAL_PAIR_FIRST_HPP

namespace metal
{
    /// \ingroup pair
    /// \brief ...
    template<typename pair>
    struct first
    {};

    /// \ingroup pair
    /// \brief Eager adaptor for \ref first.
    template<typename pair>
    using first_t = typename metal::first<pair>::type;
}

namespace metal
{
    template<template<typename...> class pair, typename x, typename y>
    struct first<pair<x, y>>
    {
        using type = x;
    };
}

#endif
