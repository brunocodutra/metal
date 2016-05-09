// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

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
}

HIDDEN(namespace)
{
/// [ex3]
template<typename array> //evaluable for array types
using expr = std::enable_if_t<!!std::rank<array>::value, array>;
/// [ex3]
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
