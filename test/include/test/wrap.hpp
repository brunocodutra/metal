// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_TEST_WRAP_HPP
#define BOOST_MPL2_TEST_WRAP_HPP

#include "test/functions.hpp"

namespace test
{
    template<typename... args>
    struct wrap
    {
        using type = wrap<args...>;
    };

    using wrapper = n_ary<wrap>;
}

#endif
