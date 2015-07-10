// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

struct x {using type = x;};
struct y {using type = y;};
struct z {using type = z;};
struct w {using type = w;};

static_assert(std::is_same<if_t<std::true_type, x>, x>{}, "");

static_assert(std::is_same<if_t<std::true_type, x, y>, x>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, y>, y>{}, "");

static_assert(std::is_same<if_t<std::true_type, x, std::true_type, y>, x>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, std::true_type, y>, y>{}, "");

static_assert(std::is_same<if_t<std::true_type, x, std::true_type, y, z>, x>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, std::true_type, y, z>, y>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, std::false_type, y, z>, z>{}, "");

static_assert(std::is_same<if_t<std::true_type, x, std::true_type, y, std::true_type, z>, x>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, std::true_type, y, std::true_type, z>, y>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, std::false_type, y, std::true_type, z>, z>{}, "");

static_assert(std::is_same<if_t<std::true_type, x, std::true_type, y, std::true_type, z, w>, x>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, std::true_type, y, std::true_type, z, w>, y>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, std::false_type, y, std::true_type, z, w>, z>{}, "");
static_assert(std::is_same<if_t<std::false_type, x, std::false_type, y, std::false_type, z, w>, w>{}, "");

using tautology = std::integral_constant<char, 'c'>;
using contradiction = std::integral_constant<unsigned long, 0UL>;

static_assert(if_t<tautology, std::true_type>{}, "");

static_assert(if_t<tautology, std::true_type, std::false_type>{}, "");
static_assert(if_t<contradiction, std::false_type, std::true_type>{}, "");

