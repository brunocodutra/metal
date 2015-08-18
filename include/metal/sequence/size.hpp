// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_SEQUENCE_SIZE_HPP
#define METAL_SEQUENCE_SIZE_HPP

#include <metal/number/number.hpp>
#include <metal/optional/extract.hpp>

#include <cstddef>

namespace metal
{
    /// \ingroup sequece
    /// \brief ...
    template<typename seq>
    struct size
    {};

    /// \ingroup sequence
    /// \brief Eager adaptor for \ref size.
    template<typename seq>
    using size_t = extract<metal::size<seq>>;

    template<template<typename...> class list, typename... vals>
    struct size<list<vals...>> :
            number<std::size_t, sizeof...(vals)>
    {};
}

#endif
