#include <metal.hpp>

#include "test.hpp"

#define ENTRY(M, N, ...) EXPR(_)<__VA_ARGS__, ENUM(N, VALUE FIX(M))>

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, VALUE(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, NUMBER(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, PAIR(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LIST(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, MAP(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(INC(M)) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (BOOL(N == 1 && M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(INC(M)) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (BOOL(N == 1 && M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(INC(M)) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (BOOL(M && M == N && M < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(INC(M)) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (BOOL(M && M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(INC(M)) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (BOOL(M && M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(INC(M)) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (BOOL(N == 1 && M == N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, VALUE FIX(M)), LIST(N)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, NUMBER FIX(M)), LIST(N)>), (BOOL(N == 1))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, PAIR FIX(M)), LIST(N)>), (BOOL(N == 1 || N == 2))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, LIST FIX(M)), LIST(N)>), (BOOL(N == 1 || (N && M == N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, MAP FIX(M)), LIST(N)>), (BOOL(N == 1 || (N && M == N)))); \
    CHECK((metal::is_invocable<metal::lambda<metal::accumulate>, LAMBDA(_) COMMA(N) ENUM(N, LAMBDA FIX(M)), LIST(N)>), (BOOL(N == 1))); \
    CHECK((metal::accumulate<LAMBDA(_), VALUE(N), ENUM(INC(N), LIST FIX(M))>), (FOLD_LEFT(M, INC(N), ENTRY, VALUE(N)))); \
    CHECK((metal::accumulate<LAMBDA(2), NUMBER(2), metal::list<TAGSX20(M) COMMA(AND(M, N)) TAGSX20(N)>>), (NUMBER(2))); \
/**/

GEN(MATRIX)

