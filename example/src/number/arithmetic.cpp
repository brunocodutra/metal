// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/arithmetic.hpp>
#include <metal/optional/optional.hpp>

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [inc]
static_assert(std::is_same</**/metal::inc_t</**/metal::integer<-10>>, metal::integer<-9>>::value, "");
static_assert(std::is_same</**/metal::inc_t</**/metal::number<short, 0>>, metal::number<short, 1>>::value, "");
/// [inc]
}

ANONYMOUS(namespace)
{
/// [dec]
static_assert(std::is_same</**/metal::dec_t</**/metal::integer<-10>>, metal::integer<-11>>::value, "");
static_assert(std::is_same</**/metal::dec_t</**/metal::number<short, 0>>, metal::number<short, -1>>::value, "");
/// [dec]
}

ANONYMOUS(namespace)
{
/// [neg]
static_assert(std::is_same</**/metal::neg_t</**/metal::integer<-10>>, metal::integer<10>>::value, "");
static_assert(std::is_same</**/metal::neg_t</**/metal::number<short, 0>>, metal::number<short, 0>>::value, "");
/// [neg]
}

ANONYMOUS(namespace)
{
/// [add]
using x = metal::add_t<
    metal::integer<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -1>>::value, "");
/// [add]
}

ANONYMOUS(namespace)
{
/// [sub]
using x = metal::sub_t<
    metal::integer<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -13>>::value, "");
/// [sub]
}

ANONYMOUS(namespace)
{
/// [mul]
using x = metal::mul_t<
    metal::integer<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -35>>::value, "");
/// [mul]
}

ANONYMOUS(namespace)
{
/// [div]
using x = metal::div_t<
    metal::integer<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -1>>::value, "");
static_assert(!metal::is_just</**/metal::div</**/metal::integer<1>, metal::integer<0>>>::value, "");
/// [div]
}

ANONYMOUS(namespace)
{
/// [mod]
using x = metal::mod_t<
    metal::integer<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, 0>>::value, "");
static_assert(!metal::is_just</**/metal::mod</**/metal::integer<1>, metal::integer<0>>>::value, "");
/// [mod]
}

ANONYMOUS(namespace)
{
/// [pow]
using x = metal::pow_t<
    metal::integer<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -16807>>::value, "");
static_assert(!metal::is_just</**/metal::pow</**/metal::integer<0>, metal::integer<0>>>::value, "");
static_assert(!metal::is_just</**/metal::pow</**/metal::integer<0>, metal::integer<-3>>>::value, "");
/// [pow]
}
