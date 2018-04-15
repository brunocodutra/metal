#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::abs>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::abs<NUMBER(M)>), (NUMBER(M))); \
    CHECK((metal::abs<NUMBER(-M)>), (NUMBER(M))); \
/**/

GEN(MATRIX)

