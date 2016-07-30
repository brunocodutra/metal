// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

#include "test/preprocessor.hpp"

namespace test
{
    using val0 = void;
    using val1 = void*;
    using val2 = int[];
    using val3 = int(*)[];
    using val4 = int[42];
    using val5 = int(*)[42];
    union val6 {template<typename...> struct type;};
    using val7 = val6::template type<>;
    enum  val8 {type};
}

#define VAL(N) CAT(test::val, N)
#define VALS(N) ENUM(N, VAL)

#endif
