// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include <tuple>

#include "example.hpp"

/// [SFINAE]
template<typename num>
constexpr metal::if_<metal::is_number<num>, metal::int_> make() {
    return num::value;
} // instantiated for Numbers only

template<typename seq>
constexpr metal::apply<metal::lambda<std::tuple>, seq> make() {
    return {};
} // instantiated for Lists only

static_assert(make<metal::number<42>>() == 42, "");
static_assert(make<metal::list<int, char>>() == std::tuple<int, char>{}, "");
/// [SFINAE]

