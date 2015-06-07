// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_TEST_EXPRESSIONS_HPP
#define BOOST_MPL2_TEST_EXPRESSIONS_HPP

#include "test/wrap.hpp"

namespace test
{
    template<typename = void>
    struct nullexpr :
            test::wrap<>
    {};

    template<typename x>
    struct unexpr :
            test::wrap<x>
    {};

    template<typename x, typename y>
    struct binexpr :
            test::wrap<x, y>
    {};

    template<typename... args>
    struct n_expr :
            test::wrap<args...>
    {};
}

#endif
