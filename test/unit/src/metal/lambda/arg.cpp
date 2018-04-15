#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::arg<INC(M)>), (CAT(metal::_, INC(M)))); \
    CHECK((metal::is_lambda<metal::arg<INC(M)>>), (TRUE)); \
    CHECK((metal::is_invocable<metal::arg<INC(M)> COMMA(N) VALUES(N)>), (BOOL(M < N))); \
    CHECK((metal::invoke<metal::arg<INC(M)>, VALUES(INC(M))>), (VALUE(M))); \
/**/

GEN(MATRIX)
