// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_SEQUENCES_HPP
#define METAL_TEST_SEQUENCES_HPP

#include "test/values.hpp"

namespace test
{
    template<typename...>
    union seq
    {
        using type = seq;
    };

    template<typename...>
    struct seq0;

    template<>
    struct seq0<>
    {
        using type = seq0;
    };

    template<typename>
    class seq1
    {
    public:
        using type = seq1;
    };

    template<typename x, typename y>
    using seq2 = seq<x, y>;

    using list0 = seq0<>;
    using list1 = seq1<v0>;
    using list2 = seq2<v0, v1>;
    using list3 = seq<v0, v1, v2>;
    using list4 = seq<v0, v1, v2, v3>;
    using list5 = seq<v0, v1, v2, v3, v4>;
    using list6 = seq<v0, v1, v2, v3, v4, v5>;
    using list7 = seq<v0, v1, v2, v3, v4, v5, v6>;
    using list8 = seq<v0, v1, v2, v3, v4, v5, v6, v7>;
    using list9 = seq<v0, v1, v2, v3, v4, v5, v6, v7, v8>;
}

#endif

