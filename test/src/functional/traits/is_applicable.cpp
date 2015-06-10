/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/traits/is_applicable.hpp>

#include "test/variadic.hpp"
#include "test/types.hpp"
#include "test/functions.hpp"
#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((not_<is_applicable<>>));

BOOST_METAL_ASSERT((is_applicable<test::a>));
BOOST_METAL_ASSERT((is_applicable<test::b>));
BOOST_METAL_ASSERT((is_applicable<test::c>));
BOOST_METAL_ASSERT((is_applicable<test::d>));
BOOST_METAL_ASSERT((is_applicable<test::e>));
BOOST_METAL_ASSERT((is_applicable<test::f>));
BOOST_METAL_ASSERT((is_applicable<test::g>));
BOOST_METAL_ASSERT((is_applicable<test::h>));
BOOST_METAL_ASSERT((is_applicable<test::i>));
BOOST_METAL_ASSERT((is_applicable<test::j>));

BOOST_METAL_ASSERT((is_applicable<test::a, void>));
BOOST_METAL_ASSERT((is_applicable<test::b, void>));
BOOST_METAL_ASSERT((is_applicable<test::c, void>));
BOOST_METAL_ASSERT((is_applicable<test::d, void>));
BOOST_METAL_ASSERT((is_applicable<test::e, void>));
BOOST_METAL_ASSERT((is_applicable<test::f, void>));
BOOST_METAL_ASSERT((is_applicable<test::g, void>));
BOOST_METAL_ASSERT((is_applicable<test::h, void>));
BOOST_METAL_ASSERT((is_applicable<test::i, void>));
BOOST_METAL_ASSERT((is_applicable<test::j, void>));

BOOST_METAL_ASSERT((is_applicable<test::a, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::b, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::c, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::d, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::e, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::f, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::g, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::h, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::i, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::j, void, void*>));

BOOST_METAL_ASSERT((is_applicable<test::unary<test::incomplete>>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::empty>>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::evaluable>>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::call>>));

BOOST_METAL_ASSERT((is_applicable<test::unary<test::incomplete>, void>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::empty>, void>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::evaluable>, void>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::call>, void>));

BOOST_METAL_ASSERT((is_applicable<test::unary<test::incomplete>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::empty>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::evaluable>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::unary<test::call>, void, void*>));

BOOST_METAL_ASSERT((is_applicable<test::binary<test::incomplete>>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::empty>>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::evaluable>>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::call>>));

BOOST_METAL_ASSERT((is_applicable<test::binary<test::incomplete>, void>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::empty>, void>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::evaluable>, void>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::call>, void>));

BOOST_METAL_ASSERT((is_applicable<test::binary<test::incomplete>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::empty>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::evaluable>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::binary<test::call>, void, void*>));

BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::incomplete>>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::empty>>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::evaluable>>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::call>>));

BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::incomplete>, void>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::empty>, void>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::evaluable>, void>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::call>, void>));

BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::incomplete>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::empty>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::evaluable>, void, void*>));
BOOST_METAL_ASSERT((is_applicable<test::n_ary<test::call>, void, void*>));
