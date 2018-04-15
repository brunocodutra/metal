#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, LIST(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, MAP(M)>), (BOOL(M == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::second>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::second<PAIR(M)>), (VALUE(M))); \
/**/

GEN(MATRIX)

