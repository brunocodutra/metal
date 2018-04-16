#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, VALUE(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, VALUE(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, VALUE(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, VALUE(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, VALUE(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, VALUE(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, VALUE(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, NUMBER(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, NUMBER(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, NUMBER(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, NUMBER(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, NUMBER(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, NUMBER(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, NUMBER(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, PAIR(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, PAIR(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, PAIR(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, PAIR(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, PAIR(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, PAIR(M), LAMBDA(N)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, PAIR(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LIST(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LIST(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LIST(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LIST(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LIST(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LIST(M), LAMBDA(N)>), (BOOL(!M || N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LIST(M), LAMBDA(_)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, MAP(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, MAP(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, MAP(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, MAP(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, MAP(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, MAP(M), LAMBDA(N)>), (BOOL(!M || N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, MAP(M), LAMBDA(_)>), (BOOL(!M))); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(M), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(M), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(M), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(M), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(M), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(M), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(M), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(_), VALUE(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(_), NUMBER(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(_), PAIR(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(_), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(_), MAP(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(_), LAMBDA(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::find_if>, LAMBDA(_), LAMBDA(_)>), (FALSE)); \
    CHECK((metal::find_if<PAIR(M), metal::lambda<metal::is_number>>), (NUMBER(0))); \
    CHECK((metal::find_if<LIST(M), metal::lambda<metal::is_number>>), (NUMBER(M))); \
    CHECK((metal::find_if<MAP(M), metal::lambda<metal::is_number>>), (NUMBER(M))); \
    CHECK((metal::find_if<PAIR(M), metal::lambda<metal::is_pair>>), (NUMBER(2))); \
    CHECK((metal::find_if<LIST(M), metal::lambda<metal::is_pair>>), (NUMBER(M))); \
    CHECK((metal::find_if<MAP(M), metal::lambda<metal::is_pair>>), (NUMBER(0))); \
    CHECK((metal::find_if<PAIR(M), metal::lambda<metal::is_lambda>>), (NUMBER(2))); \
    CHECK((metal::find_if<LIST(M), metal::lambda<metal::is_lambda>>), (NUMBER(M))); \
    CHECK((metal::find_if<MAP(M), metal::lambda<metal::is_lambda>>), (NUMBER(M))); \
    CHECK((metal::find_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_number>>), (NUMBER(0))); \
    CHECK((metal::find_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_pair>>), (BOOL(M))); \
    CHECK((metal::find_if<metal::list<ENUM(M, FWD, NUMBER, PAIR, LAMBDA)>, metal::lambda<metal::is_lambda>>), (NUMBER(IF(M)(2, 0)))); \
/**/

GEN(MATRIX)

