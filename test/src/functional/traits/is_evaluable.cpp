// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/traits/is_evaluable.hpp>
#include <metal.hpp>

#include "test.hpp"

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

static_assert(not_<is_evaluable<test::alias>>::value, "");
static_assert(not_<is_evaluable<test::empty>>::value, "");
static_assert(not_<is_evaluable<test::call>>::value, "");
static_assert(not_<is_evaluable<test::union_>>::value, "");
static_assert(is_evaluable<test::evaluable>::value, "");

static_assert(not_<is_evaluable<test::alias, test::a0>>::value, "");
static_assert(not_<is_evaluable<test::empty, test::a0>>::value, "");
static_assert(not_<is_evaluable<test::call, test::a0>>::value, "");
static_assert(not_<is_evaluable<test::union_, test::a0>>::value, "");
static_assert(is_evaluable<test::evaluable, test::a0>::value, "");

static_assert(not_<is_evaluable<test::alias, test::a0, test::a1>>::value, "");
static_assert(not_<is_evaluable<test::empty, test::a0, test::a1>>::value, "");
static_assert(not_<is_evaluable<test::call, test::a0, test::a1>>::value, "");
static_assert(not_<is_evaluable<test::union_, test::a0, test::a1>>::value, "");
static_assert(is_evaluable<test::evaluable, test::a0, test::a1>::value, "");
