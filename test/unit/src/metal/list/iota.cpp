#include <metal.hpp>

#include "test.hpp"

#define ENTRY(N, A, B) NUMBER(A*N + B)

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, VALUE(M), VALUE(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, VALUE(M), NUMBER(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, VALUE(M), PAIR(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, VALUE(M), LIST(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, VALUE(M), MAP(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, VALUE(M), LAMBDA(N), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, VALUE(M), LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, NUMBER(M), VALUE(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, NUMBER(M), NUMBER(N), NUMBER(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, NUMBER(M), PAIR(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, NUMBER(M), LIST(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, NUMBER(M), MAP(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, NUMBER(M), LAMBDA(N), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, NUMBER(M), LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, PAIR(M), VALUE(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, PAIR(M), NUMBER(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, PAIR(M), PAIR(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, PAIR(M), LIST(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, PAIR(M), MAP(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, PAIR(M), LAMBDA(N), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, PAIR(M), LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LIST(M), VALUE(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LIST(M), NUMBER(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LIST(M), PAIR(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LIST(M), LIST(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LIST(M), MAP(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LIST(M), LAMBDA(N), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LIST(M), LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, MAP(M), VALUE(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, MAP(M), NUMBER(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, MAP(M), PAIR(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, MAP(M), LIST(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, MAP(M), MAP(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, MAP(M), LAMBDA(N), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, MAP(M), LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(M), VALUE(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(M), NUMBER(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(M), PAIR(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(M), LIST(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(M), MAP(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(M), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(M), LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(_), VALUE(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(_), NUMBER(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(_), PAIR(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(_), LIST(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(_), MAP(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(_), LAMBDA(N), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::iota>, LAMBDA(_), LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::iota<NUMBER(M), NUMBER(N)>), (metal::list<ENUM(N, ENTRY, 1, M)>)); \
    CHECK((metal::iota<NUMBER(M), NUMBER(N), NUMBER(M)>), (metal::list<ENUM(N, ENTRY, M, M)>)); \
    CHECK((metal::iota<NUMBER(M), NUMBER(-N), NUMBER(-M)>), (metal::list<ENUM(N, ENTRY, M, M)>)); \
    CHECK((metal::iota<NUMBER(-M), NUMBER(N)>), (metal::list<ENUM(N, ENTRY, 1, -M)>)); \
    CHECK((metal::iota<NUMBER(-M), NUMBER(N), NUMBER(M)>), (metal::list<ENUM(N, ENTRY, M, -M)>)); \
    CHECK((metal::iota<NUMBER(-M), NUMBER(-N)>), (metal::list<ENUM(N, ENTRY, -1, -M)>)); \
    CHECK((metal::iota<NUMBER(-M), NUMBER(-N), NUMBER(M)>), (metal::list<ENUM(N, ENTRY, -M, -M)>)); \
    CHECK((metal::iota<NUMBER(-M), NUMBER(N), NUMBER(-M)>), (metal::list<ENUM(N, ENTRY, -M, -M)>)); \
    CHECK((metal::iota<NUMBER(-M), NUMBER(-N), NUMBER(-M)>), (metal::list<ENUM(N, ENTRY, M, -M)>)); \
/**/

GEN(MATRIX)
