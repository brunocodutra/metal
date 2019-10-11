#ifndef METAL_TEST_NUMBERS_HPP
#define METAL_TEST_NUMBERS_HPP

#include "test/preprocessor.hpp"

#define FACT_0 1
#define FACT_1 1
#define FACT_2 FACT_1 * 2
#define FACT_3 FACT_2 * 3
#define FACT_4 FACT_3 * 4
#define FACT_5 FACT_4 * 5
#define FACT_6 FACT_5 * 6
#define FACT_7 FACT_6 * 7
#define FACT_8 FACT_7 * 8
#define FACT_9 FACT_8 * 9
#define FACT(N) (CAT(FACT_, N))

#define NUMBER(N) metal::number<N>
#define NUMBERS(N) ENUM(N, NUMBER)

#define BOOL(B) metal::number<!!(B)>
#define TRUE BOOL(true)
#define FALSE BOOL(false)

#define NUMBERX20(N) X20(NUMBER, N)
#define NUMBERSX20(N) ENUM(N, FWD, NUMBERX20)

#endif
