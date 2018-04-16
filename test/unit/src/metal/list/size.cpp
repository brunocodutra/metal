#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::size>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::size<PAIR(M)>), (NUMBER(2))); \
    CHECK((metal::size<LIST(M)>), (NUMBER(M))); \
    CHECK((metal::size<MAP(M)>), (NUMBER(M))); \
    CHECK((metal::size<metal::list<VALUES(M) COMMA(AND(M, N)) VALUES(N)>>), (NUMBER(M + N))); \
    CHECK((metal::size<metal::list<ENUM(M, VALUE FIX(N))>>), (NUMBER(M))); \
/**/

GEN(MATRIX)

