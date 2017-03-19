// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include <memory>
#include <utility>

#include "example.hpp"

HIDE(
/// [pair1]
using pair = metal::list<int, unsigned>;
/// [pair1]

IS_SAME(metal::is_pair<pair>, metal::true_);
)

HIDE(
/// [not_a_pair1]
using not_a_pair = std::pair<int, unsigned>; // not a List
/// [not_a_pair1]

IS_SAME(metal::is_pair<not_a_pair>, metal::false_);
)

HIDE(
/// [is_pair]
IS_SAME(metal::is_pair<std::pair<int, unsigned>>, metal::false_);
IS_SAME(metal::is_pair<metal::pair<int, unsigned>>, metal::true_);
IS_SAME(metal::is_pair<metal::list<void, void*>>, metal::true_);
IS_SAME(metal::is_pair<metal::list<void>>, metal::false_);
/// [is_pair]
)

HIDE(
/// [as_pair]
IS_SAME(metal::as_pair<std::pair<int, char>>, metal::list<int, char>);

IS_SAME(
    metal::as_pair<std::unique_ptr<int>>,
    metal::pair<int, std::default_delete<int>>
);
/// [as_pair]
)

HIDE(
/// [first]
IS_SAME(metal::first<metal::pair<void, void*>>, void);
/// [first]
)

HIDE(
/// [second]
IS_SAME(metal::second<metal::pair<void, void*>>, void*);
/// [second]
)
