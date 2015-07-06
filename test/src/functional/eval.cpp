// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/eval.hpp>

#include "test/types.hpp"
#include "test/functions.hpp"
#include "test/expressions.hpp"
#include "test/main.hpp"

namespace example
{
    /// [eval]
    template<typename>
    struct except_void
    {
        struct type;
    };

    template<>
    struct except_void<void>
    {
        //empty
    };

    using r1 = metal::eval<except_void, int>;
    static_assert(std::is_base_of<except_void<int>, r1>::value, "");

    using r2 = metal::eval<except_void, void>; //identity<void> is not evaluable
    static_assert(!std::is_base_of<except_void<void>, r2>::value, "");
    /// [eval]
}

using namespace metal;

namespace test
{
    template<typename = void>
    struct e0;

    template<>
    struct e0<> :
            test::nullary<test::evaluable>::call<>
    {};

    template<typename x>
    using e1 = typename test::unary<test::evaluable>::call<x>;

    template<typename x, typename y>
    using e2 = typename test::binary<test::evaluable>::call<x, y>;

    template<typename... args>
    using en = typename test::n_ary<test::evaluable>::call<args...>;
}

METAL_ASSERT((std::is_same<eval_t<test::e0>, test::e0<>::type>));
METAL_ASSERT((std::is_same<eval_t<test::e1, test::a>, test::e1<test::a>::type>));
METAL_ASSERT((std::is_same<eval_t<test::e2, test::a, test::b>, test::e2<test::a, test::b>::type>));

METAL_ASSERT((std::is_same<eval_t<test::en>, test::en<>::type>));
METAL_ASSERT((std::is_same<eval_t<test::en, test::a>, test::en<test::a>::type>));
METAL_ASSERT((std::is_same<eval_t<test::en, test::a, test::b>, test::en<test::a, test::b>::type>));
METAL_ASSERT((std::is_same<eval_t<test::en, test::a, test::b, test::c>, test::en<test::a, test::b, test::c>::type>));
METAL_ASSERT((std::is_same<eval_t<test::en, test::a, test::b, test::c, test::d>, test::en<test::a, test::b, test::c, test::d>::type>));
