// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_QUOTE_HPP
#define METAL_FUNCTIONAL_QUOTE_HPP

#include <metal/functional/eval.hpp>

namespace metal
{
    template<template<typename...> class expr>
    struct quote
    {
        using type = quote;

        template<typename... args>
        using call = eval<expr, args...>;
    };
}

#endif
