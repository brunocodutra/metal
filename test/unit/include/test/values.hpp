// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

#include "test/preprocessor.hpp"

namespace test
{
    enum  val0 {value, type};
    union val1 {struct value {};};
    union val2 {struct type {};};
    union val3 {template<typename...> struct type;};
    using val4 = val3::template type<>;
    class val5 final {};
    using val6 = int;
    using val7 = int*;
    using val8 = int[];
    using val9 = int();

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
