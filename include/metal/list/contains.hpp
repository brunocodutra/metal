// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_CONTAINS_HPP
#define METAL_LIST_CONTAINS_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename val>
    struct contains
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref contains.
    template<typename list, typename val>
    using contains_t = typename contains<list, val>::type;
}

#include <metal/core/are_same.hpp>
#include <metal/number/number.hpp>
#include <metal/number/logical/or.hpp>

namespace metal
{
    template<template<typename...> class list, typename val>
    struct contains<list<>, val> :
        boolean<false>
    {};

    template<template<typename...> class list, typename... vals, typename val>
    struct contains<list<vals...>, val> :
        or_<are_same_t<vals, val>...>
    {};
}

#endif
