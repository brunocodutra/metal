#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, LIST(M)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::keys>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::keys<MAP(M)>), (metal::list<NUMBERS(M)>)); \
/**/

GEN(MATRIX)

