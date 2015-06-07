// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/traits/is_quotable.hpp>

#include "test/variadic.hpp"
#include "test/functions.hpp"
#include "test/main.hpp"

using namespace boost::metal;

BOOST_METAL_ASSERT((is_quotable<test::fundamental>));
BOOST_METAL_ASSERT((is_quotable<test::incomplete>));
BOOST_METAL_ASSERT((is_quotable<test::empty>));
BOOST_METAL_ASSERT((is_quotable<test::evaluable>));
BOOST_METAL_ASSERT((is_quotable<test::call>));

BOOST_METAL_ASSERT((is_quotable<test::fundamental, void>));
BOOST_METAL_ASSERT((is_quotable<test::incomplete, void>));
BOOST_METAL_ASSERT((is_quotable<test::empty, void>));
BOOST_METAL_ASSERT((is_quotable<test::evaluable, void>));
BOOST_METAL_ASSERT((is_quotable<test::call, void>));

BOOST_METAL_ASSERT((is_quotable<test::fundamental, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::incomplete, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::empty, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::evaluable, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::call, void, void*>));

BOOST_METAL_ASSERT((not_<is_quotable<test::unary<test::incomplete>::call>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::unary<test::empty>::call>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::unary<test::evaluable>::call>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::unary<test::call>::call>>));

BOOST_METAL_ASSERT((is_quotable<test::unary<test::incomplete>::call, void>));
BOOST_METAL_ASSERT((is_quotable<test::unary<test::empty>::call, void>));
BOOST_METAL_ASSERT((is_quotable<test::unary<test::evaluable>::call, void>));
BOOST_METAL_ASSERT((is_quotable<test::unary<test::call>::call, void>));

BOOST_METAL_ASSERT((not_<is_quotable<test::unary<test::incomplete>::call, void, void*>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::unary<test::empty>::call, void, void*>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::unary<test::evaluable>::call, void, void*>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::unary<test::call>::call, void, void*>>));

BOOST_METAL_ASSERT((not_<is_quotable<test::binary<test::incomplete>::call>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::binary<test::empty>::call>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::binary<test::evaluable>::call>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::binary<test::call>::call>>));

BOOST_METAL_ASSERT((not_<is_quotable<test::binary<test::incomplete>::call, void>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::binary<test::empty>::call, void>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::binary<test::evaluable>::call, void>>));
BOOST_METAL_ASSERT((not_<is_quotable<test::binary<test::call>::call, void>>));

BOOST_METAL_ASSERT((is_quotable<test::binary<test::incomplete>::call, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::binary<test::empty>::call, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::binary<test::evaluable>::call, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::binary<test::call>::call, void, void*>));

BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::incomplete>::call>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::empty>::call>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::evaluable>::call>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::call>::call>));

BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::incomplete>::call, void>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::empty>::call, void>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::evaluable>::call, void>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::call>::call, void>));

BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::incomplete>::call, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::empty>::call, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::evaluable>::call, void, void*>));
BOOST_METAL_ASSERT((is_quotable<test::n_ary<test::call>::call, void, void*>));
