// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_SIZE_HPP
#define METAL_SEQUENCE_SIZE_HPP

#include <cstddef>
#include <type_traits>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename seq>
    struct size;

    /// \ingroup sequence
    /// \brief Eager adaptor for \ref size.
    template<typename seq>
    using size_t = typename metal::size<seq>::type;

    template<template<typename...> class list, typename... values>
    struct size<list<values...>> :
            std::integral_constant<std::size_t, sizeof...(values)>
    {};
}

#endif
