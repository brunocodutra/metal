// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [ex1]
template<typename>
union expr
{
    struct type; //evaluable for every argument
};
/// [ex1]

static_assert(metal::is_just<expr<void>>::value, "");
}

ANONYMOUS(namespace)
{
/// [ex2]
template<typename...>
struct expr
{
    //not evaluable for any set of arguments
};
/// [ex2]

static_assert(!metal::is_just<expr<void>>::value, "");
}

ANONYMOUS(namespace)
{
/// [ex3]
template<typename array> //evaluable for array types
using expr = std::enable_if<!!std::rank<array>::value, array>;
/// [ex3]

static_assert(!metal::is_just<expr<int>>::value, "");
static_assert(metal::is_just<expr<int[]>>::value, "");
static_assert(metal::is_just<expr<int[][1]>>::value, "");
}

ANONYMOUS(namespace)
{
/// [nex1]
struct not_an_expr //not a template
{
    struct type;
};
/// [nex1]
}

ANONYMOUS(namespace)
{
/// [nex2]
template<template<typename...> class... exprs> //non-type parameter
struct not_an_expr
{
    struct type;
};
/// [nex2]
}

ANONYMOUS(namespace)
{
/// [nex3]
template<typename integral, integral integral_value> //non-type parameter
using not_an_expr = std::integral_constant<integral, integral_value>;
/// [nex3]
}
