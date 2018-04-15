#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::numbers<ENUM(M, ID)>), (metal::list<NUMBERS(M)>)); \
/**/

GEN(MATRIX)
