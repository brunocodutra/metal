#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, NUMBER(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::eval>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::eval<NUMBER(N)>), (NUMBER(N))); \
    CHECK((metal::eval<metal::value<VALUE(N)>>), (VALUE(N))); \
/**/

GEN(MATRIX)
