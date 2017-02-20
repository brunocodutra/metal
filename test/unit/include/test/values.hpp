// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

#include "test/preprocessor.hpp"

namespace test
{
    enum  val0 {type};
    union val1 {template<typename...> struct type;};
    using val2 = val1::template type<>;
    using val3 = decltype(nullptr);
    class val4 final {};
    using val5 = int;
    using val6 = int*;
    using val7 = int[];
    using val8 = int const;
    using val9 = int volatile;

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
