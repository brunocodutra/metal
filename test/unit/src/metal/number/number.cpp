#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, VALUE(M)>), (BOOL(M < 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::as_number>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_number<VALUE(M)>), (FALSE)); \
    CHECK((metal::is_number<NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_number<NUMBER(-M)>), (TRUE)); \
    CHECK((metal::is_number<PAIR(M)>), (FALSE)); \
    CHECK((metal::is_number<LIST(M)>), (FALSE)); \
    CHECK((metal::is_number<MAP(M)>), (FALSE)); \
    CHECK((metal::is_number<LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_number<LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_number<metal::false_>), (TRUE)); \
    CHECK((metal::is_number<metal::true_>), (TRUE)); \
    CHECK((metal::as_number<VALUE(0)>), (NUMBER(0))); \
    CHECK((metal::as_number<VALUE(1)>), (NUMBER(1))); \
/**/

GEN(MATRIX)
