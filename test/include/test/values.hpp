// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

namespace test
{
    enum a0 {type};
    union a1 {};
    using a2 = a1(a0);
    using a3 = a2* const;
    using a4 = a2* volatile;
    using a5 = a3 volatile;
    using a6 = a5[1];
    using a7 = a6[];
    using a8 = a7&&;
    using a9 = a8&;
}

#endif
