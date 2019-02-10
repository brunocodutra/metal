#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, VALUE(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, VALUE(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, VALUE(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, VALUE(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, VALUE(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, VALUE(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, NUMBER(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, NUMBER(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, NUMBER(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, NUMBER(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, NUMBER(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, NUMBER(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, NUMBER(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, PAIR(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, PAIR(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, PAIR(M), LAMBDA(N)>), (BOOL(N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, PAIR(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LIST(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LIST(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LIST(M), LAMBDA(N)>), (BOOL(N == 2 || M < 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LIST(M), LAMBDA(_)>), (BOOL(M < 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, MAP(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, MAP(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, MAP(M), LAMBDA(N)>), (BOOL(N == 2 || M < 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, MAP(M), LAMBDA(_)>), (BOOL(M < 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::sort>, LAMBDA(_), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::sort<metal::list<NUMBERSX20(M)>, metal::lambda<metal::greater>>), (metal::list<RENUM(M, FWD, NUMBERX20)>)); \
    CHECK((metal::sort<metal::list<NUMBERSX20(M)>, metal::lambda<metal::less>>), (metal::list<NUMBERSX20(M)>)); \
    CHECK((metal::sort<metal::list<ENUM(INC(N), NUMBERS FIX(INC(M)))>, metal::lambda<metal::less>>), (metal::list<ENUM(INC(M), FWD, RENUM(INC(N), NUMBER NIL))>)); \
/**/

GEN(MATRIX)
