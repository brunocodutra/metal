// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/number/add.hpp>
#include <metal/number/dec.hpp>
#include <metal/number/div.hpp>
#include <metal/number/inc.hpp>
#include <metal/number/max.hpp>
#include <metal/number/min.hpp>
#include <metal/number/mod.hpp>
#include <metal/number/mul.hpp>
#include <metal/number/neg.hpp>
#include <metal/number/pow.hpp>
#include <metal/number/sub.hpp>
#include <metal/lambda/invoke.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [inc]
static_assert(std::is_same<metal::inc<metal::int_<-10>>, metal::int_<-9>>::value, "");
static_assert(std::is_same<metal::inc<metal::number<short, 0>>, metal::number<short, 1>>::value, "");
/// [inc]
}

HIDDEN(namespace)
{
/// [dec]
static_assert(std::is_same<metal::dec<metal::int_<-10>>, metal::int_<-11>>::value, "");
static_assert(std::is_same<metal::dec<metal::number<short, 0>>, metal::number<short, -1>>::value, "");
/// [dec]
}

HIDDEN(namespace)
{
/// [neg]
static_assert(std::is_same<metal::neg<metal::int_<-10>>, metal::int_<10>>::value, "");
static_assert(std::is_same<metal::neg<metal::number<short, 0>>, metal::number<short, 0>>::value, "");
/// [neg]
}

HIDDEN(namespace)
{
/// [add]
using x = metal::add<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -1>>::value, "");
/// [add]
}

HIDDEN(namespace)
{
/// [sub]
using x = metal::sub<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -13>>::value, "");
/// [sub]
}

HIDDEN(namespace)
{
/// [mul]
using x = metal::mul<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -35>>::value, "");
/// [mul]
}

HIDDEN(namespace)
{
/// [div]
using x = metal::div<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -1>>::value, "");
static_assert(!metal::is_invocable<metal::lambda<metal::div>, metal::int_<1>, metal::int_<0>>::value, "");
/// [div]
}

HIDDEN(namespace)
{
/// [mod]
using x = metal::mod<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, 0>>::value, "");
static_assert(!metal::is_invocable<metal::lambda<metal::mod>, metal::int_<1>, metal::int_<0>>::value, "");
/// [mod]
}

HIDDEN(namespace)
{
/// [pow]
using x = metal::pow<
    metal::int_<-7>,
    metal::number<long, 5>,
    metal::number<short, 1>
>;

static_assert(std::is_same<x, metal::number<long, -16807>>::value, "");
static_assert(!metal::is_invocable<metal::lambda<metal::pow>, metal::int_<0>, metal::int_<-3>>::value, "");
/// [pow]
}
