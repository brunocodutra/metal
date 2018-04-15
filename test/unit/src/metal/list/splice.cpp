#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, VALUE(M), VALUE(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, VALUE(M), NUMBER(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, VALUE(M), PAIR(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, VALUE(M), LIST(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, VALUE(M), MAP(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, VALUE(M), LAMBDA(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, VALUE(M), LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, NUMBER(M), VALUE(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, NUMBER(M), NUMBER(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, NUMBER(M), PAIR(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, NUMBER(M), LIST(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, NUMBER(M), MAP(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, NUMBER(M), LAMBDA(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, NUMBER(M), LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, PAIR(M), VALUE(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, PAIR(M), NUMBER(N), PAIR(N)>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, PAIR(M), LIST(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, PAIR(M), MAP(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, PAIR(M), LAMBDA(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, PAIR(M), LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LIST(M), VALUE(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LIST(M), NUMBER(N), LIST(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LIST(M), PAIR(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LIST(M), MAP(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LIST(M), LAMBDA(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LIST(M), LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, MAP(M), VALUE(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, MAP(M), NUMBER(N), MAP(N)>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, MAP(M), PAIR(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, MAP(M), LIST(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, MAP(M), LAMBDA(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, MAP(M), LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(M), VALUE(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(M), NUMBER(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(M), PAIR(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(M), LIST(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(M), MAP(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(M), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(M), LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(_), VALUE(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(_), NUMBER(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(_), PAIR(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(_), LIST(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(_), MAP(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(_), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::splice>, LAMBDA(_), LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::splice<metal::list<VALUES(M) COMMA(AND(M, CMPL(M))) VALUES(CMPL(M))>, NUMBER(M), PAIR(N)>), (metal::list<VALUES(M) COMMA(M) NUMBER(N), VALUE(N) COMMA(CMPL(M)) VALUES(CMPL(M))>)); \
/**/

GEN(MATRIX)

