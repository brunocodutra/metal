// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_TEST_TYPES_HPP
#define BOOST_MPL2_TEST_TYPES_HPP

namespace test
{
    using a = void;
    using b = char[];
    using c = b*(b);
    using d = c*(c);
    using e = d*(d);
    using f = e*(e);
    using g = f*(f);
    using h = a(b,c,d,e,f,g);
    struct i {};
    struct j;
}

#endif
