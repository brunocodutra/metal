// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_SEQUENCES_HPP
#define METAL_TEST_SEQUENCES_HPP

#include "test/values.hpp"
#include "test/numbers.hpp"
#include "test/preprocessor.hpp"

#define PAIR(N) metal::list<NUM(N), VAL(N)>
#define PAIRS(N) ENUM(N, PAIR)

#define LIST(N) metal::list<VALS(N)>
#define LISTS(N) ENUM(N, LIST)

#define MAP(N) metal::list<PAIRS(N)>
#define MAPS(N) ENUM(N, MAP)

#endif

