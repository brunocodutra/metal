// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional.hpp>
#include <metal.hpp>

#include "test.hpp"

using namespace metal;

static_assert(!is_evaluable<if_, std::true_type, test::a0>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a1>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a2>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a3>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a4>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a5>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a6>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a7>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a8>::value, "");
static_assert(!is_evaluable<if_, std::true_type, test::a9>::value, "");

struct x {using type = x;};
struct y {using type = y;};
struct z {using type = z;};
struct w {using type = w;};

static_assert(std::is_same<if_t<std::true_type, x>, x>::value, "");

static_assert(std::is_same<if_t<std::true_type, x, y>, x>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, y>, y>::value, "");

static_assert(std::is_same<if_t<std::true_type, x, std::true_type, y>, x>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, std::true_type, y>, y>::value, "");

static_assert(std::is_same<if_t<std::true_type, x, std::true_type, y, z>, x>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, std::true_type, y, z>, y>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, std::false_type, y, z>, z>::value, "");

static_assert(std::is_same<if_t<std::true_type, x, std::true_type, y, std::true_type, z>, x>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, std::true_type, y, std::true_type, z>, y>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, std::false_type, y, std::true_type, z>, z>::value, "");

static_assert(std::is_same<if_t<std::true_type, x, std::true_type, y, std::true_type, z, w>, x>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, std::true_type, y, std::true_type, z, w>, y>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, std::false_type, y, std::true_type, z, w>, z>::value, "");
static_assert(std::is_same<if_t<std::false_type, x, std::false_type, y, std::false_type, z, w>, w>::value, "");

using tautology = std::integral_constant<char, 'c'>;
using contradiction = std::integral_constant<unsigned long, 0UL>;

static_assert(if_t<tautology, std::true_type>::value, "");

static_assert(if_t<tautology, std::true_type, std::false_type>::value, "");
static_assert(if_t<contradiction, std::false_type, std::true_type>::value, "");

