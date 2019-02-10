#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

#include "test/preprocessor.hpp"

namespace test {
    struct val0 {enum {value};};
    struct val1 {static int const value = 1;};
    struct val2 {static int value;};
    struct val3 {int const value;};
    struct val4 {static int value();};
    union  val5 {int value();};
    union  val6 {struct value {};};
    union  val7 {template<typename...> struct value {};};
    class  val8 final {};
    using  val9 = void;

    template<std::intmax_t> struct tag {};
}

#define VALUE(N) CAT(test::val, N)
#define VALUES(N) ENUM(N, VALUE)

#define TAG(M) test::tag<(M)>

#define TAGX20(N) X20(TAG, N)
#define TAGSX20(N) ENUM(N, FWD, TAGX20)

#endif
