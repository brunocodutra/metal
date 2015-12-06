// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/optional.hpp>

#include "example.hpp"

ANONYMOUS(struct)
{
static constexpr
/// [just]
auto obj = {0, 1};
using some = metal::just<decltype(obj)>;
using none = metal::just<>;

static_assert(!metal::is_just<none>::value, "");
static_assert(metal::is_just<some>::value, "");
static_assert(std::is_same<some::type, decltype(obj)>::value, "");
/// [just]
};

ANONYMOUS(namespace)
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

ANONYMOUS(namespace)
{
/// [optional]
struct none
{};

struct some
{
    struct type;
};

static_assert(!metal::is_just<metal::optional<none>>::value, "");
static_assert(metal::is_just<metal::optional<some>>::value, "");

static_assert(std::is_base_of<metal::nothing, metal::optional<none>>::value, "");
static_assert(std::is_base_of<metal::just<some::type>, metal::optional<some>>::value, "");
/// [optional]
}
