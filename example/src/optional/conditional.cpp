// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/conditional.hpp>
#include <metal/number/comparison.hpp>

#include "example.hpp"

HIDDEN(namespace)
{
/// [conditional]
template<typename num, typename min, typename max>
struct clip :
    metal::conditional<
        metal::greater<num, max>, max,
        metal::less<num, min>, min,
        num
    >
{};

template<typename x, typename max, typename min>
using clip_t = typename clip<x, max, min>::type;

static_assert(std::is_same<
    clip_t<metal::integer<12>, metal::integer<-10>, metal::integer<10>>,
    metal::integer<10>
>::value, "");

static_assert(std::is_same<
    clip_t<metal::integer<-12>, metal::integer<-10>, metal::integer<10>>,
    metal::integer<-10>
>::value, "");

static_assert(std::is_same<
    clip_t<metal::integer<0>, metal::integer<-10>, metal::integer<10>>,
    metal::integer<0>
>::value, "");

/// [conditional]
}
