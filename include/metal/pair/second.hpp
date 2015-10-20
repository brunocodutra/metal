// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_PAIR_SECOND_HPP
#define METAL_PAIR_SECOND_HPP

namespace metal
{
    /// \ingroup pair
    /// \brief ...
    template<typename pair>
    struct second
    {};

    /// \ingroup pair
    /// \brief Eager adaptor for \ref second.
    template<typename pair>
    using second_t = typename metal::second<pair>::type;

    template<template<typename...> class pair, typename x, typename y>
    struct second<pair<x, y>>
    {
        using type = y;
    };
}

#endif
