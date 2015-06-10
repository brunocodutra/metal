/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/core/assert.hpp>

#include "test/main.hpp"

BOOST_METAL_ASSERT((std::true_type));
BOOST_METAL_ASSERT_MSG((std::true_type), "");
BOOST_METAL_ASSERT_EXPR((true));
BOOST_METAL_ASSERT_EXPR_MSG((true), "");
