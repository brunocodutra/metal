// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_LIST_HPP
#define METAL_SEQUENCE_LIST_HPP

#include <metal/number/number.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup sequence
    /// \brief ...
    template<typename... vals>
    struct list;

    /// \ingroup sequece
    /// \brief ...
    template<typename seq>
    struct is_list;

    /// \ingroup sequence
    /// \brief Eager adaptor for \ref is_list.
    template<typename seq>
    using is_list_t = extract<metal::is_list<seq>>;

    template<typename... vals>
    struct list :
            conditional<is_list_t<list<vals...>>, just<list<vals...>>>
    {};

    template<typename>
    struct is_list :
            boolean<false>
    {};

    template<template<typename...> class seq, typename... vals>
    struct is_list<seq<vals...>> :
            boolean<true>
    {};
}

#endif
