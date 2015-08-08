// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_LIST_HPP
#define METAL_SEQUENCE_LIST_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup sequence
    /// \brief ...
    template<typename... values>
    struct list
    {
        using type = list;
    };

    /// \ingroup sequece
    /// \brief ...
    template<typename seq>
    struct is_list;

    /// \ingroup sequence
    /// \brief Eager adaptor for \ref is_list.
    template<typename seq>
    using is_list_t = typename metal::is_list<seq>::type;

    template<typename>
    struct is_list :
            boolean<false>
    {};

    template<template<typename...> class seq, typename... values>
    struct is_list<seq<values...>> :
            boolean<true>
    {};
}

#endif
