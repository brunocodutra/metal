// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include "example.hpp"

/// [sum]
using sum = metal::add</**/metal::integer<3>, metal::integer<4>>;
/// [sum]

/// [first]
using left = metal::first<sum>; // evaluates to metal::integer<4>
/// [first]

/// [second]
using right = metal::second<sum>; // evaluates to metal::integer<4>
/// [second]
