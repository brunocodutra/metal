// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

HIDDEN(namespace)
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

HIDDEN(namespace)
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

HIDDEN(namespace)
{
/// [ex3]
template<typename array> //evaluable for array types
using expr = std::enable_if<!!std::rank<array>::value, array>;
/// [ex3]

static_assert(!metal::is_just<expr<int>>::value, "");
static_assert(metal::is_just<expr<int[]>>::value, "");
static_assert(metal::is_just<expr<int[][1]>>::value, "");
}

HIDDEN(namespace)
{
/// [nex1]
struct not_an_expression //not a template
{
    struct type;
};
/// [nex1]
}

HIDDEN(namespace)
{
/// [nex2]
template<template<typename...> class... exprs> //non-type parameter
struct not_an_expression
{
    struct type;
};
/// [nex2]
}

HIDDEN(namespace)
{
/// [nex3]
template<typename integral, integral integral_value> //non-type parameter
using not_an_expression = std::integral_constant<integral, integral_value>;
/// [nex3]
}
