#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::indices>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::indices<PAIR(M)>), (metal::list<NUMBERS(2)>)); \
    CHECK((metal::indices<LIST(M)>), (metal::list<NUMBERS(M)>)); \
    CHECK((metal::indices<MAP(M)>), (metal::list<NUMBERS(M)>)); \
/**/

GEN(MATRIX)

