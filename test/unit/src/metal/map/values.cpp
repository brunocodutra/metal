#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, LIST(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::values>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::values<MAP(M)>), (metal::list<VALUES(M)>)); \
/**/

GEN(MATRIX)

