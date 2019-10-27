#include <metal.hpp>

#include "test.hpp"

#define ENTRY(M, N, ...) EXPR(_)<__VA_ARGS__, ENUM(N, VALUE FIX(M))>
#define LISTX20(M) metal::list<TAGSX20(M)>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M) COMMA(N) ENUM(N, VALUE FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M) COMMA(N) ENUM(N, NUMBER FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M) COMMA(N) ENUM(N, PAIR FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M) COMMA(N) ENUM(N, LIST FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M) COMMA(N) ENUM(N, MAP FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(M) COMMA(N) ENUM(N, LAMBDA FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M) COMMA(N) ENUM(N, VALUE FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M) COMMA(N) ENUM(N, NUMBER FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M) COMMA(N) ENUM(N, PAIR FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M) COMMA(N) ENUM(N, LIST FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M) COMMA(N) ENUM(N, MAP FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(M) COMMA(N) ENUM(N, LAMBDA FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M) COMMA(N) ENUM(N, VALUE FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M) COMMA(N) ENUM(N, NUMBER FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M) COMMA(N) ENUM(N, PAIR FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M) COMMA(N) ENUM(N, LIST FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M) COMMA(N) ENUM(N, MAP FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(M) COMMA(N) ENUM(N, LAMBDA FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M) COMMA(N) ENUM(N, VALUE FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M) COMMA(N) ENUM(N, NUMBER FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M) COMMA(N) ENUM(N, PAIR FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M) COMMA(N) ENUM(N, LIST FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M) COMMA(N) ENUM(N, MAP FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(M) COMMA(N) ENUM(N, LAMBDA FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M) COMMA(N) ENUM(N, VALUE FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M) COMMA(N) ENUM(N, NUMBER FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M) COMMA(N) ENUM(N, PAIR FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M) COMMA(N) ENUM(N, LIST FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M) COMMA(N) ENUM(N, MAP FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(M) COMMA(N) ENUM(N, LAMBDA FIX(M))>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M) COMMA(N) ENUM(N, VALUE FIX(M))>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M) COMMA(N) ENUM(N, NUMBER FIX(M))>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M) COMMA(N) ENUM(N, PAIR FIX(M))>), (BOOL(N == 1 || (N > 1 && M == N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M) COMMA(N) ENUM(N, LIST FIX(M))>), (BOOL(N == 1 || (N > 1 && M == N) || (N > 1 && M == 0)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M) COMMA(N) ENUM(N, MAP FIX(M))>), (BOOL(N == 1 || (N > 1 && M == N) || (N > 1 && M == 0)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(M) COMMA(N) ENUM(N, LAMBDA FIX(M))>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, VALUE FIX(M))>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, NUMBER FIX(M))>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, PAIR FIX(M))>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, LIST FIX(M))>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, MAP FIX(M))>), (BOOL(N > 0))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, LAMBDA FIX(M))>), (BOOL(N == 1))); \
    CHECK((metal::accumulate<LAMBDA(_), VALUE(M) COMMA(N) ENUM(N, LIST FIX(N))>), (FOLD_LEFT(N, N, ENTRY, VALUE(M)))); \
    CHECK((metal::accumulate<LAMBDA(_), VALUE(M), ENUM(INC(M), LIST FIX(N))>), (FOLD_LEFT(N, INC(M), ENTRY, VALUE(M)))); \
    CHECK((metal::accumulate<LAMBDA(INC(M)), NUMBER(INC(M)) COMMA(M) ENUM(M, LISTX20 FIX(N))>), (NUMBER(INC(M)))); \
/**/

GEN(MATRIX)

