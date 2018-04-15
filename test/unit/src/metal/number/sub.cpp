#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) VALUES(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) VALUES(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) VALUES(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) VALUES(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) VALUES(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) VALUES(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) NUMBERS(M) COMMA(N) VALUES(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) NUMBERS(M) COMMA(N) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) NUMBERS(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) NUMBERS(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) NUMBERS(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) NUMBERS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) PAIRS(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) PAIRS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) PAIRS(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) PAIRS(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) PAIRS(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) PAIRS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LISTS(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LISTS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LISTS(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LISTS(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LISTS(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LISTS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) MAPS(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) MAPS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) MAPS(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) MAPS(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) MAPS(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) MAPS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LAMBDAS(M) COMMA(N) VALUES(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LAMBDAS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LAMBDAS(M) COMMA(N) PAIRS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LAMBDAS(M) COMMA(N) LISTS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LAMBDAS(M) COMMA(N) MAPS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sub> COMMA(M) LAMBDAS(M) COMMA(N) LAMBDAS(N)>), (BOOL(!M && !N))); \
    CHECK((metal::sub<NUMBER(M) COMMA(N) NUMBERS(N)>), (NUMBER(N*(1 - N)/2 + M))); \
/**/

GEN(MATRIX)
