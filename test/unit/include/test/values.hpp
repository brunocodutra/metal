// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

#include "test/preprocessor.hpp"

namespace test
{
    class val0;
    using val1 = int;
    using val2 = int[];
    using val3 = int[42];
    using val4 = int*;
    using val5 = int(*)[];
    using val6 = int(*)[42];
    union val7 {template<typename...> struct type;};
    using val8 = val7::template type<>;
    enum  val9 {type};

    template<std::intmax_t> struct tag {};
}

#define VALUE(N) CAT(test::val, N)
#define VALUES(N) ENUM(N, VALUE)

#define TAG(M) test::tag<(M)>

#define X20(M, N) \
    M(N), M(N), M(N), M(N), M(N), M(N), M(N), M(N), M(N), M(N), \
    M(N), M(N), M(N), M(N), M(N), M(N), M(N), M(N), M(N), M(N) \
/**/

#define TAGX20(N) X20(TAG, N)
#define TAGSX20(N) ENUM(N, FWD, TAGX20)

#endif
