/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/algorithm/tag.hpp>

#include "test/types.hpp"
#include "test/main.hpp"

using namespace boost::metal;

namespace test
{
    struct tagged
    {
        struct tag;
    };

    struct tag
    {};
}

BOOST_METAL_ASSERT((std::is_same<tag<test::a>::type, tag<test::a>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::b>::type, tag<test::b>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::c>::type, tag<test::c>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::d>::type, tag<test::d>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::e>::type, tag<test::e>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::f>::type, tag<test::f>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::g>::type, tag<test::g>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::h>::type, tag<test::h>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::i>::type, tag<test::i>>));
BOOST_METAL_ASSERT((std::is_same<tag<test::j>::type, tag<test::j>>));

BOOST_METAL_ASSERT((std::is_same<tag<test::tagged>::type, test::tagged::tag>));
BOOST_METAL_ASSERT((std::is_same<tag<test::tag>::type, test::tag>));
