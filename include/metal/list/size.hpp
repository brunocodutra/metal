// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_SIZE_HPP
#define METAL_LIST_SIZE_HPP

#include <metal/number/number.hpp>

#include <cstddef>

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct size
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref size.
    template<typename list>
    using size_t = typename metal::size<list>::type;

    template<template<typename...> class list, typename... vals>
    struct size<list<vals...>> :
            number<std::size_t, sizeof...(vals)>
    {};
}

#endif
