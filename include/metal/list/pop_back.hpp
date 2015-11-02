// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_POP_BACK_HPP
#define METAL_LIST_POP_BACK_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct pop_back
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref pop_back.
    template<typename list>
    using pop_back_t = typename metal::pop_back<list>::type;
}

#include <metal/list/erase.hpp>
#include <metal/list/size.hpp>
#include <metal/number/arithmetic/dec.hpp>

namespace metal
{
    template<template<typename...> class list, typename head, typename... tail>
    struct pop_back<list<head, tail...>> :
        erase<list<head, tail...>, dec_t<size_t<list<head, tail...>>>>
    {};
}

#endif
