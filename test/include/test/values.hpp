// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

#include "test/preprocessor.hpp"

namespace test
{
    enum val0 {type};
    union val1 {template<typename...> struct type;};
    using val2 = void;
    using val3 = void();
    using val4 = val1 const;
    using val5 = val1*;
    using val6 = val1&;
    using val7 = val1&&;
    using val8 = val1[1];
    using val9 = val8[];

#define VAL(N) CAT(test::val, N)
#define VALS(N) ENUM(N, test::val)
}
#endif
