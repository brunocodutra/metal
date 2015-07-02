// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/metal/functional/eval.hpp>

#include "test/functions.hpp"
#include "test/expressions.hpp"
#include "test/main.hpp"

using namespace boost::metal;

namespace test
{
    template<typename = void>
    struct nullexpr;

    template<>
    struct nullexpr<> :
            test::nullary<test::evaluable>::template call<>
    {};

    template<typename x>
    using unexpr = typename test::unary<test::evaluable>::template call<x>;

    template<typename x, typename y>
    using binexpr = typename test::binary<test::evaluable>::template call<x, y>;

    template<typename... args>
    using n_expr = typename test::n_ary<test::evaluable>::template call<args...>;
}

BOOST_METAL_ASSERT((std::is_same<eval_t<test::nullexpr>, test::nullexpr<>::type>));
BOOST_METAL_ASSERT((std::is_same<eval_t<test::unexpr, void>, test::unexpr<void>::type>));
BOOST_METAL_ASSERT((std::is_same<eval_t<test::binexpr, void, void*>, test::binexpr<void, void*>::type>));

BOOST_METAL_ASSERT((std::is_same<eval_t<test::n_expr>, test::n_expr<>::type>));
BOOST_METAL_ASSERT((std::is_same<eval_t<test::n_expr, short>, test::n_expr<short>::type>));
BOOST_METAL_ASSERT((std::is_same<eval_t<test::n_expr, short, int>, test::n_expr<short, int>::type>));
BOOST_METAL_ASSERT((std::is_same<eval_t<test::n_expr, short, int, long>, test::n_expr<short, int, long>::type>));
BOOST_METAL_ASSERT((std::is_same<eval_t<test::n_expr, short, int, long, long long>, test::n_expr<short, int, long, long long>::type>));
