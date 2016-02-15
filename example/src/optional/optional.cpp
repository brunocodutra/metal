// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/optional.hpp>

#include "example.hpp"

HIDDEN(struct)
{
/// [just]
using none = metal::just<>;
using some = metal::just<decltype(3.14)>;

static_assert(metal::is_just<some>::value, "");
static_assert(!metal::is_just<none>::value, "");
static_assert(std::is_same<some::type, decltype(3.14)>::value, "");
/// [just]
};

HIDDEN(namespace)
{
/// [is_just]
struct none
{};

struct some
{
    struct type;
};

static_assert(!metal::is_just<none>::value, "");
static_assert(metal::is_just<some>::value, "");
/// [is_just]
}

HIDDEN(namespace)
{
/// [optional]
struct none
{};

struct some
{
    struct type;
};

static_assert(!metal::is_just</**/metal::optional<none>>::value, "");
static_assert(metal::is_just</**/metal::optional<some>>::value, "");

static_assert(std::is_base_of</**/metal::nothing, metal::optional<none>>::value, "");
static_assert(std::is_base_of</**/metal::just<some::type>, metal::optional<some>>::value, "");
/// [optional]
}
