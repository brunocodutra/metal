// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

namespace test
{
    union a {};
    using b = void;
    using c = b(a);
    using d = c* const;
    using e = c* volatile;
    using f = d volatile;
    using g = f[1];
    using h = g[];
    using i = h&&;
    using j = i&;
}

#endif
