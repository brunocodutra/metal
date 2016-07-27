// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_HPP
#define METAL_TEST_HPP

#include <type_traits>

namespace test
{
    template<typename... _>
    struct length :
        std::integral_constant<std::size_t, sizeof...(_)>
    {};
}

#include "test/expressions.hpp"
#include "test/lambda.hpp"
#include "test/numbers.hpp"
#include "test/preprocessor.hpp"
#include "test/sequences.hpp"
#include "test/values.hpp"

int main() {
    return 0;
}

#endif
