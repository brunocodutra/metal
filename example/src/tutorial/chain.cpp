// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/apply.hpp>
#include <metal/functional/arg.hpp>
#include <metal/functional/bind.hpp>
#include <metal/functional/protect.hpp>

#include "example.hpp"

template<typename x>
using f = std::add_pointer<x>;

template<typename x>
using g = std::add_const<x>;

using chain = metal::protect_t<metal::bind_t<metal::_1, metal::bind_t<metal::_2, metal::_3>>>;
static_assert(std::is_same<metal::apply_t<chain, f<metal::_1>, g<metal::_1>, void>, f<g<void>::type>::type>::value, "");
static_assert(std::is_same<metal::apply_t<chain, g<metal::_1>, f<metal::_1>, void>, g<f<void>::type>::type>::value, "");

using once = metal::protect_t<metal::bind_t<chain, metal::protect_t<metal::_1>, metal::_1, metal::_2>>;
static_assert(std::is_same<metal::apply_t<once, f<metal::_1>, void>, f<void>::type>::value, "");

using twice = metal::protect_t<metal::bind_t<chain, metal::_1, metal::_1, metal::_2>>;
static_assert(std::is_same<metal::apply_t<twice, f<metal::_1>, void>, f<f<void>::type>::type>::value, "");

using thrice = metal::protect_t<metal::bind_t<once, metal::_1, metal::bind_t<twice, metal::_1, metal::_2>>>;
static_assert(std::is_same<metal::apply_t<thrice, f<metal::_1>, void>, f<f<f<void>::type>::type>::type>::value, "");
