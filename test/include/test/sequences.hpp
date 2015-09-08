// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_SEQUENCES_HPP
#define METAL_TEST_SEQUENCES_HPP

#include "test/numbers.hpp"
#include "test/preprocessor.hpp"
#include "test/values.hpp"

namespace test
{
    template<typename...> class seq;

    namespace detail
    {
        template<typename...>
        struct seq0_impl;

        template<>
        struct seq0_impl<>
        {
            using type = seq<>;
        };
    }

    template<typename... _>
    using seq0 = typename detail::seq0_impl<_...>::type;

    template<ENUM( 1, typename BAR)> union  seq1;
    template<ENUM( 2, typename BAR)> union  seq2;
    template<ENUM( 3, typename BAR)> union  seq3;
    template<ENUM( 4, typename BAR)> union  seq4;
    template<ENUM( 5, typename BAR)> union  seq5;
    template<ENUM( 6, typename BAR)> struct seq6;
    template<ENUM( 7, typename BAR)> struct seq7;
    template<ENUM( 8, typename BAR)> struct seq8;
    template<ENUM( 9, typename BAR)> struct seq9;
    template<ENUM(10, typename BAR)> struct seq10;

    using list0  = seq0<VALS(0)>;
    using list1  = seq1<VALS(1)>;
    using list2  = seq2<VALS(2)>;
    using list3  = seq3<VALS(3)>;
    using list4  = seq4<VALS(4)>;
    using list5  = seq5<VALS(5)>;
    using list6  = seq6<VALS(6)>;
    using list7  = seq7<VALS(7)>;
    using list8  = seq8<VALS(8)>;
    using list9  = seq9<VALS(9)>;
    using list10 = seq10<VALS(10)>;

#define PAIR(N) test::seq2<NUM(N), VAL(N)>
#define PAIRS(N) ENUM(N, FORWARD(PAIR))

    using map0  = seq0<PAIRS(0)>;
    using map1  = seq1<PAIRS(1)>;
    using map2  = seq2<PAIRS(2)>;
    using map3  = seq3<PAIRS(3)>;
    using map4  = seq4<PAIRS(4)>;
    using map5  = seq5<PAIRS(5)>;
    using map6  = seq6<PAIRS(6)>;
    using map7  = seq7<PAIRS(7)>;
    using map8  = seq8<PAIRS(8)>;
    using map9  = seq9<PAIRS(9)>;
    using map10 = seq10<PAIRS(10)>;
}

#define SEQ(...) CAT(test::seq, __VA_ARGS__)

#define LIST(N) CAT(test::list, N)
#define LISTS(N) ENUM(N, test::list)

#define MAP(N) CAT(test::map, N)
#define MAPS(N) ENUM(N, test::map)

#endif

