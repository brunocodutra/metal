#ifndef METAL_TEST_SEQUENCES_HPP
#define METAL_TEST_SEQUENCES_HPP

#include "test/numbers.hpp"
#include "test/preprocessor.hpp"
#include "test/values.hpp"

#define PAIR(N) metal::list<NUMBER(N), VALUE(N)>
#define PAIRS(N) ENUM(N, PAIR)

#define LIST(N) metal::list<VALUES(N)>
#define LISTS(N) ENUM(N, LIST)

#define MAP(N) metal::list<PAIRS(N)>
#define MAPS(N) ENUM(N, MAP)

#endif
