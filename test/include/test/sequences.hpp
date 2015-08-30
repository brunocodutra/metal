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
    template<typename...> struct seq;

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

    template<typename... _> using seq0 = typename detail::seq0_impl<_...>::type;
    template<_enum( 1, typename _bar)> union seq1;
    template<_enum( 2, typename _bar)> union seq2;
    template<_enum( 3, typename _bar)> class seq3;
    template<_enum( 4, typename _bar)> class seq4;
    template<_enum( 5, typename _bar)> struct seq5;
    template<_enum( 6, typename _bar)> struct seq6;
    template<_enum( 7, typename _)> using seq7  = seq<_enum( 7, _)>;
    template<_enum( 8, typename _)> using seq8  = seq<_enum( 8, _)>;
    template<_enum( 9, typename _)> using seq9  = seq<_enum( 9, _)>;
    template<_enum(10, typename _)> using seq10 = seq<_enum(10, _)>;

#define _seq(...) _cat(test::seq, __VA_ARGS__)
#define _seqs(N) _enum(N, test::seq)

    using list0  = seq0<_vals(0)>;
    using list1  = seq1<_vals(1)>;
    using list2  = seq2<_vals(2)>;
    using list3  = seq3<_vals(3)>;
    using list4  = seq4<_vals(4)>;
    using list5  = seq5<_vals(5)>;
    using list6  = seq6<_vals(6)>;
    using list7  = seq7<_vals(7)>;
    using list8  = seq8<_vals(8)>;
    using list9  = seq9<_vals(9)>;
    using list10 = seq10<_vals(10)>;

#define _list(...) _cat(test::list, __VA_ARGS__)
#define _lists(N) _enum(N, test::list)

    using pair0 = seq2<num0, val0>;
    using pair1 = seq <num1, val1>;
    using pair2 = seq2<num2, val2>;
    using pair3 = seq <num3, val3>;
    using pair4 = seq2<num4, val4>;
    using pair5 = seq <num5, val5>;
    using pair6 = seq2<num6, val6>;
    using pair7 = seq <num7, val7>;
    using pair8 = seq2<num8, val8>;
    using pair9 = seq <num9, val9>;

#define _pair(...) _cat(test::pair, __VA_ARGS__)
#define _pairs(N) _enum(N, test::pair)

    using map0  = seq0<_pairs(0)>;
    using map1  = seq1<_pairs(1)>;
    using map2  = seq2<_pairs(2)>;
    using map3  = seq3<_pairs(3)>;
    using map4  = seq4<_pairs(4)>;
    using map5  = seq5<_pairs(5)>;
    using map6  = seq6<_pairs(6)>;
    using map7  = seq7<_pairs(7)>;
    using map8  = seq8<_pairs(8)>;
    using map9  = seq9<_pairs(9)>;
    using map10 = seq10<_pairs(10)>;

#define _map(...) _cat(test::map, __VA_ARGS__)
#define _maps(N) _enum(N, test::map)
}
#endif

