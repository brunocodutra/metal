// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

HIDDEN(namespace)
{
/// [ex1]
struct opt
{
    struct type; //just some value
};
/// [ex1]

static_assert(metal::is_just<opt>::value, "");
}

HIDDEN(namespace)
{
/// [ex2]
using opt = void; //nothing - undefined ::type
/// [ex2]

static_assert(!metal::is_just<opt>::value, "");
}

HIDDEN(namespace)
{
/// [ex3]
struct opt
{
    template<typename...>
    struct type; //nothing - ::type is not a model of Value
};
/// [ex3]

static_assert(!metal::is_just<opt>::value, "");
}

HIDDEN(namespace)
{
/// [ex4]
struct optional1
{
    struct type; //just some value
};

struct optional2
{
    struct type; //just some other value
};

struct optional3 :
    optional1,
    optional2
{
    //nothing - ambiguous ::type
};
/// [ex4]

static_assert(metal::is_just<optional1>::value, "");
static_assert(metal::is_just<optional2>::value, "");
static_assert(!metal::is_just<optional3>::value, "");
}

