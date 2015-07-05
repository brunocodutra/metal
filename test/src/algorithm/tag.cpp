// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/algorithm/tag.hpp>

#include "test/types.hpp"
#include "test/main.hpp"

using namespace metal;

namespace test
{
    struct tagged
    {
        struct tag;
    };

    struct tag
    {};
}

METAL_ASSERT((std::is_same<tag<test::a>::type, tag<test::a>>));
METAL_ASSERT((std::is_same<tag<test::b>::type, tag<test::b>>));
METAL_ASSERT((std::is_same<tag<test::c>::type, tag<test::c>>));
METAL_ASSERT((std::is_same<tag<test::d>::type, tag<test::d>>));
METAL_ASSERT((std::is_same<tag<test::e>::type, tag<test::e>>));
METAL_ASSERT((std::is_same<tag<test::f>::type, tag<test::f>>));
METAL_ASSERT((std::is_same<tag<test::g>::type, tag<test::g>>));
METAL_ASSERT((std::is_same<tag<test::h>::type, tag<test::h>>));
METAL_ASSERT((std::is_same<tag<test::i>::type, tag<test::i>>));
METAL_ASSERT((std::is_same<tag<test::j>::type, tag<test::j>>));

METAL_ASSERT((std::is_same<tag<test::tagged>::type, test::tagged::tag>));
METAL_ASSERT((std::is_same<tag<test::tag>::type, test::tag>));
