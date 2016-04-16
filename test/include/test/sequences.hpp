// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_SEQUENCES_HPP
#define METAL_TEST_SEQUENCES_HPP

#include "test/numbers.hpp"
#include "test/preprocessor.hpp"
#include "test/values.hpp"

#include <type_traits>

namespace test
{
    template<typename...> class seq;

    template<typename... _>
    using seq0 = std::enable_if_t<sizeof...(_) == 0, seq<_...>>;

    template<EVAL(ENUM,  1, typename BAR)> union  seq1;
    template<EVAL(ENUM,  2, typename BAR)> union  seq2;
    template<EVAL(ENUM,  3, typename BAR)> union  seq3;
    template<EVAL(ENUM,  4, typename BAR)> union  seq4;
    template<EVAL(ENUM,  5, typename BAR)> union  seq5;
    template<EVAL(ENUM,  6, typename BAR)> struct seq6;
    template<EVAL(ENUM,  7, typename BAR)> struct seq7;
    template<EVAL(ENUM,  8, typename BAR)> struct seq8;
    template<EVAL(ENUM,  9, typename BAR)> struct seq9;
    template<EVAL(ENUM, 10, typename BAR)> struct seq10;
}

#define SEQ(...) CAT(test::seq, __VA_ARGS__)

#define VEC(N) SEQ()<VALS(N)>
#define VECS(N) ENUM(N, LIFT(VEC))

#define PAIR(N) SEQ(2)<NUM(N), VAL(N)>
#define PAIRS(N) ENUM(N, LIFT(PAIR))

#define LIST(N) SEQ(N)<VALS(N)>
#define LISTS(N) ENUM(N, LIFT(LIST))

#define MAP(N) SEQ(N)<PAIRS(N)>
#define MAPS(N) ENUM(N, LIFT(MAP))

#endif

