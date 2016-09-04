// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [map1]
using m = metal::list<>; // an empty map
/// [map1]

IS_SAME(metal::is_map<m>, metal::true_);
)

HIDE(
/// [map2]
using m = metal::list<
    metal::list<int, long>,
    metal::list<float, double>
>;
/// [map2]

IS_SAME(metal::is_map<m>, metal::true_);
)

HIDE(
/// [not_a_map1]
using not_a_map = metal::list< // repeated keys
    metal::list<int, int*>,
    metal::list<int, int&>
>;
/// [not_a_map1]

IS_SAME(metal::is_map<not_a_map>, metal::false_);
)

HIDE(
/// [not_a_map2]
using not_a_map = metal::list< // not a list of pairs
    metal::list<int>,
    metal::list<int, int&>
>;
/// [not_a_map2]

IS_SAME(metal::is_map<not_a_map>, metal::false_);
)

HIDE(
/// [is_map]
using m = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(metal::is_map<m>, metal::true_);
IS_SAME(metal::is_map<metal::list<>>, metal::true_);
IS_SAME(metal::is_map<metal::pair<int, int*>>, metal::false_);
/// [is_map]
)

HIDE(
/// [order]
using m = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(metal::order<m, int>, metal::number<0>);
IS_SAME(metal::order<m, char>, metal::number<1>);
IS_SAME(metal::order<m, float>, metal::number<2>);
/// [order]
)

HIDE(
/// [has_key]
using m = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(metal::has_key<m, int>, metal::true_);
IS_SAME(metal::has_key<m, char>, metal::true_);
IS_SAME(metal::has_key<m, float>, metal::true_);
IS_SAME(metal::has_key<m, void>, metal::false_);
/// [has_key]
)

HIDE(
/// [at_key]
using m = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(metal::at_key<m, int>, metal::number<sizeof(int)>);
IS_SAME(metal::at_key<m, char>, metal::number<sizeof(char)>);
IS_SAME(metal::at_key<m, float>, metal::number<sizeof(float)>);
/// [at_key]
)

HIDE(
/// [insert_key]
using m = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(
    metal::insert_key<m, void, metal::number<0>>,
    metal::map<
        metal::pair<int, metal::number<sizeof(int)>>,
        metal::pair<char, metal::number<sizeof(char)>>,
        metal::pair<float, metal::number<sizeof(float)>>,
        metal::pair<void, metal::number<0>>
    >
);
/// [insert_key]
)

HIDE(
/// [erase_key]
using m = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(
    metal::erase_key<m, int>,
    metal::map<
        metal::pair<char, metal::number<sizeof(char)>>,
        metal::pair<float, metal::number<sizeof(float)>>
    >
);

IS_SAME(
    metal::erase_key<m, char>,
    metal::map<
        metal::pair<int, metal::number<sizeof(int)>>,
        metal::pair<float, metal::number<sizeof(float)>>
    >
);

IS_SAME(
    metal::erase_key<m, float>,
    metal::map<
        metal::pair<int, metal::number<sizeof(int)>>,
        metal::pair<char, metal::number<sizeof(char)>>
    >
);
/// [erase_key]
)

HIDE(
/// [keys]
using m = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(metal::keys<m>, metal::list<int, char, float>);
/// [keys]
)

HIDE(
/// [values]
using m = metal::map<
    metal::pair<int, metal::number<sizeof(int)>>,
    metal::pair<char, metal::number<sizeof(char)>>,
    metal::pair<float, metal::number<sizeof(float)>>
>;

IS_SAME(
    metal::values<m>,
    metal::list<
        metal::number<sizeof(int)>,
        metal::number<sizeof(char)>,
        metal::number<sizeof(float)>
    >
);
/// [values]
)
