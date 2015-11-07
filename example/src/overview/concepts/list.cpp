// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

ANONYMOUS
{
/// [ex1]
template<typename>
union single;

using list = single<int>; // size == 1
/// [ex1]

static_assert(metal::is_list_t<list>::value, "");
static_assert(metal::size_t<list>::value == 1, "");
}

ANONYMOUS
{
/// [ex2]
template<typename _, typename = _*>
struct couple;

using list = couple<int /*, int* */>; // size == 2 - beware of hidden elements!
/// [ex2]

static_assert(metal::is_list_t<list>::value, "");
static_assert(metal::size_t<list>::value == 2, "");
}

ANONYMOUS
{
/// [ex3]
template<typename...>
class many;

using list = many<>; // size == 0
/// [ex3]

static_assert(metal::is_list_t<list>::value, "");
static_assert(metal::size_t<list>::value == 0, "");
}

ANONYMOUS
{
/// [nex1]
using not_a_list = union{}; // not a template instantiation
/// [nex1]

static_assert(!metal::is_list_t<not_a_list>::value, "");
}

ANONYMOUS
{
/// [nex2]
template<typename t, t...>
struct numbers;

using not_a_list = numbers<int /*, ...*/>; // non-type arguments
/// [nex2]

static_assert(!metal::is_list_t<not_a_list>::value, "");
}

ANONYMOUS
{
/// [nex3]
template<template<typename...> class>
class expression;

using not_a_list = expression<std::add_pointer>; // non-type argument
/// [nex3]

static_assert(!metal::is_list_t<not_a_list>::value, "");
}
