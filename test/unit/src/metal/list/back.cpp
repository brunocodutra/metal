#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LIST(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, MAP(M)>), (BOOL(M > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::back>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::back<PAIR(M)>), (VALUE(M))); \
    CHECK((metal::back<LIST(INC(M))>), (VALUE(M))); \
    CHECK((metal::back<MAP(INC(M))>), (PAIR(M))); \
/**/

GEN(MATRIX)

