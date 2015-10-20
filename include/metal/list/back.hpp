// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_BACK_HPP
#define METAL_LIST_BACK_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct back
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref back.
    template<typename list>
    using back_t = typename metal::back<list>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/number/arithmetic/dec.hpp>

namespace metal
{
    template<template<typename...> class list, typename... vals>
    struct back<list<vals...>> :
        at<list<vals...>, dec_t<size_t<list<vals...>>>>
    {};
}

#endif
