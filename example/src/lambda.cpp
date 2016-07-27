// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [lbd1]
template<template<typename...> class>
struct func;

using lbd = func<std::add_pointer_t>;
/// [lbd1]

static_assert(metal::is_lambda<lbd>::value, "");
)

HIDE(
/// [not_a_lbd1]
template<template<typename...> class, template<typename...> class> // not unary
struct func_pair;

using not_a_lbd = func_pair<std::add_pointer_t, std::add_lvalue_reference_t>;
/// [not_a_lbd1]

static_assert(!metal::is_lambda<not_a_lbd>::value, "");
)
