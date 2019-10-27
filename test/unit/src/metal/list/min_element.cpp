#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, VALUE(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, VALUE(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, VALUE(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, VALUE(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, VALUE(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, VALUE(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, VALUE(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, NUMBER(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, NUMBER(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, NUMBER(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, NUMBER(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, NUMBER(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, NUMBER(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, NUMBER(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, NUMBER(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, PAIR(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, PAIR(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, PAIR(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, PAIR(M), LAMBDA(N)>), (BOOL(N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, PAIR(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LIST(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LIST(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LIST(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LIST(M), LAMBDA(N)>), (BOOL((N == 2 && M > 0) || M == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LIST(M), LAMBDA(_)>), (BOOL(M == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, MAP(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, MAP(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, MAP(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, MAP(M), LAMBDA(N)>), (BOOL((N == 2 && M > 0) || M == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, MAP(M), LAMBDA(_)>), (BOOL(M == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>, VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>, NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>, PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>, LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>, MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>, metal::list<NUMBERS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>, LAMBDA(N)>), (BOOL((N == 2 && M > 0) || M == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, metal::list<NUMBERS(M)>, LAMBDA(_)>), (BOOL(M == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(M)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min_element>, LAMBDA(_), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::min_element<metal::list<NUMBERSX20(INC(M))>, metal::lambda<metal::greater>>), (metal::number<M>)); \
    CHECK((metal::min_element<metal::list<NUMBERSX20(INC(M))>, metal::lambda<metal::less>>), (metal::number<0>)); \
    CHECK((metal::min_element<metal::list<ENUM(INC(N), NUMBERS FIX(INC(M)))>, metal::lambda<metal::less>>), (metal::number<0>)); \
/**/

GEN(MATRIX)
