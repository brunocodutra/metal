// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/eval.hpp>
#include <metal.hpp>

#include "test.hpp"

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
    static_assert(std::is_base_of<except_void<int>, r1>{}, "");

    using r2 = metal::eval<except_void, void>; //except_void<void> is nil
    static_assert(!std::is_base_of<except_void<void>, r2>{}, "");
    /// [eval]
}

using namespace metal;

static_assert(std::is_same<eval_t<test::evaluable>, test::evaluable<>::type>{}, "");
static_assert(std::is_same<eval_t<test::evaluable_union>, test::evaluable_union<>::type>{}, "");

static_assert(std::is_same<eval_t<test::e0>, test::e0<>::type>{}, "");
static_assert(std::is_same<eval_t<test::e1, test::a0>, test::e1<test::a0>::type>{}, "");
static_assert(std::is_same<eval_t<test::e2, test::a0, test::a1>, test::e2<test::a0, test::a1>::type>{}, "");

static_assert(std::is_same<eval_t<test::en>, test::en<>::type>{}, "");
static_assert(std::is_same<eval_t<test::en, test::a0>, test::en<test::a0>::type>{}, "");
static_assert(std::is_same<eval_t<test::en, test::a0, test::a1>, test::en<test::a0, test::a1>::type>{}, "");
static_assert(std::is_same<eval_t<test::en, test::a0, test::a1, test::a2>, test::en<test::a0, test::a1, test::a2>::type>{}, "");
static_assert(std::is_same<eval_t<test::en, test::a0, test::a1, test::a2, test::a3>, test::en<test::a0, test::a1, test::a2, test::a3>::type>{}, "");
