#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::inc>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::inc<NUMBER(M)>), (NUMBER(M + 1))); \
/**/

GEN(MATRIX)

