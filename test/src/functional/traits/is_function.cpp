// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/traits/is_function.hpp>

#include "test/variadic.hpp"
#include "test/types.hpp"
#include "test/functions.hpp"
#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((not_<is_function<test::a>>));
BOOST_METAL_ASSERT((not_<is_function<test::b>>));
BOOST_METAL_ASSERT((not_<is_function<test::c>>));
BOOST_METAL_ASSERT((not_<is_function<test::d>>));
BOOST_METAL_ASSERT((not_<is_function<test::e>>));
BOOST_METAL_ASSERT((not_<is_function<test::f>>));
BOOST_METAL_ASSERT((not_<is_function<test::g>>));
BOOST_METAL_ASSERT((not_<is_function<test::h>>));
BOOST_METAL_ASSERT((not_<is_function<test::i>>));
BOOST_METAL_ASSERT((not_<is_function<test::j>>));

BOOST_METAL_ASSERT((not_<is_function<test::call<>>>));

BOOST_METAL_ASSERT((is_function<test::unary<test::incomplete>>));
BOOST_METAL_ASSERT((is_function<test::unary<test::empty>>));
BOOST_METAL_ASSERT((is_function<test::unary<test::evaluable>>));
BOOST_METAL_ASSERT((is_function<test::unary<test::call>>));

BOOST_METAL_ASSERT((is_function<test::binary<test::incomplete>>));
BOOST_METAL_ASSERT((is_function<test::binary<test::empty>>));
BOOST_METAL_ASSERT((is_function<test::binary<test::evaluable>>));
BOOST_METAL_ASSERT((is_function<test::binary<test::call>>));

BOOST_METAL_ASSERT((is_function<test::n_ary<test::incomplete>>));
BOOST_METAL_ASSERT((is_function<test::n_ary<test::empty>>));
BOOST_METAL_ASSERT((is_function<test::n_ary<test::evaluable>>));
BOOST_METAL_ASSERT((is_function<test::n_ary<test::call>>));
