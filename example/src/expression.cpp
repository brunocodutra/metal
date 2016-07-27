// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [expr1]
template<typename... vals>
using expr = std::integral_constant<std::size_t, sizeof...(vals)>;
/// [expr1]
)

HIDE(
/// [expr2]
template<typename array>
using expr = std::enable_if_t<
    std::is_array<array>::value,
    std::remove_all_extents_t<array>
>;
/// [expr2]
)

HIDE(
/// [expr3]
template<typename, typename>
struct expr;
/// [expr3]
)

HIDE(
/// [not_an_expr1]
struct not_an_expression // not a template
{
    struct type;
};
/// [not_an_expr1]
)

HIDE(
/// [not_an_expr2]
template<template<typename...> class...> // non-type parameter
struct not_an_expression
{
    struct type;
};
/// [not_an_expr2]
)

HIDE(
/// [not_an_expr3]
template<typename t, t v> // non-type parameter
using not_an_expression = std::integral_constant<t, v>;
/// [not_an_expr3]
)
