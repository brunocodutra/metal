// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_LISTS_HPP
#define METAL_TEST_LISTS_HPP

#include "test/numbers.hpp"
#include "test/values.hpp"

namespace test
{
    template<typename...>
    union seq
    {};

    template<typename>
    struct seq1;

    template<typename x, typename y>
    class seq2;

    using list0 = seq<>;
    using list1 = seq1<val0>;
    using list2 = seq2<val0, val1>;
    using list3 = seq<val0, val1, val2>;
    using list4 = seq<val0, val1, val2, val3>;
    using list5 = seq<val0, val1, val2, val3, val4>;
    using list6 = seq<val0, val1, val2, val3, val4, val5>;
    using list7 = seq<val0, val1, val2, val3, val4, val5, val6>;
    using list8 = seq<val0, val1, val2, val3, val4, val5, val6, val7>;
    using list9 = seq<val0, val1, val2, val3, val4, val5, val6, val7, val8>;

    using map0 = seq<>;
    using map1 = seq1<seq2<num0, val0>>;
    using map2 = seq2<seq2<num0, val0>, seq<num1, val1>>;
    using map3 = seq<seq2<num0, val0>, seq<num1, val1>, seq2<num2, val2>>;
    using map4 = seq<seq2<num0, val0>, seq<num1, val1>, seq2<num2, val2>, seq<num3, val3>>;
    using map5 = seq<seq2<num0, val0>, seq<num1, val1>, seq2<num2, val2>, seq<num3, val3>, seq2<num4, val4>>;
    using map6 = seq<seq2<num0, val0>, seq<num1, val1>, seq2<num2, val2>, seq<num3, val3>, seq2<num4, val4>, seq<num5, val5>>;
    using map7 = seq<seq2<num0, val0>, seq<num1, val1>, seq2<num2, val2>, seq<num3, val3>, seq2<num4, val4>, seq<num5, val5>, seq2<num6, val6>>;
    using map8 = seq<seq2<num0, val0>, seq<num1, val1>, seq2<num2, val2>, seq<num3, val3>, seq2<num4, val4>, seq<num5, val5>, seq2<num6, val6>, seq<num7, val7>>;
    using map9 = seq<seq2<num0, val0>, seq<num1, val1>, seq2<num2, val2>, seq<num3, val3>, seq2<num4, val4>, seq<num5, val5>, seq2<num6, val6>, seq<num7, val7>, seq2<num8, val8>>;
}

#endif

