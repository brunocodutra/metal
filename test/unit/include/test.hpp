// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_HPP
#define METAL_TEST_HPP

#include <type_traits>

#include "test/expressions.hpp"
#include "test/lambda.hpp"
#include "test/numbers.hpp"
#include "test/preprocessor.hpp"
#include "test/sequences.hpp"
#include "test/values.hpp"

#define CHECK_IMPL(X, Y) \
    static_assert(std::is_same<ID X, ID Y>::value, #X " == " #Y) \
/**/

#define CHECK(X, Y) EXPAND(CHECK_IMPL SCAN((X, Y)))

int main() {
    return 0;
}

#endif
