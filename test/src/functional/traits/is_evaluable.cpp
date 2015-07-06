// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_evaluable.hpp>

#include "test/functions.hpp"
#include "test/main.hpp"

using namespace metal;

namespace example
{
    /// [is_evaluable]
    template<typename...>
    struct evaluable
    {
        struct type;
    };

    template<typename...>
    struct not_evaluable
    {
        //empty
    };

    static_assert(metal::is_evaluable<evaluable>::value, "");
    static_assert(metal::is_evaluable<evaluable, void>::value, "");
    static_assert(metal::is_evaluable<evaluable, void, void*>::value, "");

    static_assert(!metal::is_evaluable<not_evaluable>::value, "");
    static_assert(!metal::is_evaluable<not_evaluable, void>::value, "");
    static_assert(!metal::is_evaluable<not_evaluable, void, void*>::value, "");
    /// [is_evaluable]
}

METAL_ASSERT((not_<is_evaluable<test::fundamental>>));
METAL_ASSERT((not_<is_evaluable<test::incomplete>>));
METAL_ASSERT((not_<is_evaluable<test::empty>>));
METAL_ASSERT((is_evaluable<test::evaluable>));
METAL_ASSERT((not_<is_evaluable<test::call>>));

METAL_ASSERT((not_<is_evaluable<test::fundamental, void>>));
METAL_ASSERT((not_<is_evaluable<test::incomplete, void>>));
METAL_ASSERT((not_<is_evaluable<test::empty, void>>));
METAL_ASSERT((is_evaluable<test::evaluable, void>));
METAL_ASSERT((not_<is_evaluable<test::call, void>>));

METAL_ASSERT((not_<is_evaluable<test::fundamental, void, void*>>));
METAL_ASSERT((not_<is_evaluable<test::incomplete, void, void*>>));
METAL_ASSERT((not_<is_evaluable<test::empty, void, void*>>));
METAL_ASSERT((is_evaluable<test::evaluable, void, void*>));
METAL_ASSERT((not_<is_evaluable<test::call, void, void*>>));

METAL_ASSERT((not_<is_evaluable<test::unary<test::incomplete>::call>>));
METAL_ASSERT((not_<is_evaluable<test::unary<test::empty>::call>>));
METAL_ASSERT((not_<is_evaluable<test::unary<test::evaluable>::call>>));
METAL_ASSERT((not_<is_evaluable<test::unary<test::call>::call>>));

METAL_ASSERT((not_<is_evaluable<test::unary<test::incomplete>::call, void>>));
METAL_ASSERT((not_<is_evaluable<test::unary<test::empty>::call, void>>));
METAL_ASSERT((is_evaluable<test::unary<test::evaluable>::call, void>));
METAL_ASSERT((not_<is_evaluable<test::unary<test::call>::call, void>>));

METAL_ASSERT((not_<is_evaluable<test::unary<test::incomplete>::call, void, void*>>));
METAL_ASSERT((not_<is_evaluable<test::unary<test::empty>::call, void, void*>>));
METAL_ASSERT((not_<is_evaluable<test::unary<test::evaluable>::call, void, void*>>));
METAL_ASSERT((not_<is_evaluable<test::unary<test::call>::call, void, void*>>));

METAL_ASSERT((not_<is_evaluable<test::binary<test::incomplete>::call>>));
METAL_ASSERT((not_<is_evaluable<test::binary<test::empty>::call>>));
METAL_ASSERT((not_<is_evaluable<test::binary<test::evaluable>::call>>));
METAL_ASSERT((not_<is_evaluable<test::binary<test::call>::call>>));

METAL_ASSERT((not_<is_evaluable<test::binary<test::incomplete>::call, void>>));
METAL_ASSERT((not_<is_evaluable<test::binary<test::empty>::call, void>>));
METAL_ASSERT((not_<is_evaluable<test::binary<test::evaluable>::call, void>>));
METAL_ASSERT((not_<is_evaluable<test::binary<test::call>::call, void>>));

METAL_ASSERT((not_<is_evaluable<test::binary<test::incomplete>::call, void, void*>>));
METAL_ASSERT((not_<is_evaluable<test::binary<test::empty>::call, void, void*>>));
METAL_ASSERT((is_evaluable<test::binary<test::evaluable>::call, void, void*>));
METAL_ASSERT((not_<is_evaluable<test::binary<test::call>::call, void, void*>>));

METAL_ASSERT((not_<is_evaluable<test::n_ary<test::incomplete>::call>>));
METAL_ASSERT((not_<is_evaluable<test::n_ary<test::empty>::call>>));
METAL_ASSERT((is_evaluable<test::n_ary<test::evaluable>::call>));
METAL_ASSERT((not_<is_evaluable<test::n_ary<test::call>::call>>));

METAL_ASSERT((not_<is_evaluable<test::n_ary<test::incomplete>::call, void>>));
METAL_ASSERT((not_<is_evaluable<test::n_ary<test::empty>::call, void>>));
METAL_ASSERT((is_evaluable<test::n_ary<test::evaluable>::call, void>));
METAL_ASSERT((not_<is_evaluable<test::n_ary<test::call>::call, void>>));

METAL_ASSERT((not_<is_evaluable<test::n_ary<test::incomplete>::call, void, void*>>));
METAL_ASSERT((not_<is_evaluable<test::n_ary<test::empty>::call, void, void*>>));
METAL_ASSERT((is_evaluable<test::n_ary<test::evaluable>::call, void, void*>));
METAL_ASSERT((not_<is_evaluable<test::n_ary<test::call>::call, void, void*>>));
