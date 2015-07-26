// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

namespace test
{
    enum v0 {type};
    union v1 {};
    using v2 = v1();
    using v3 = v2* const;
    using v4 = v2* volatile;
    using v5 = v3 volatile;
    using v6 = v5[1];
    using v7 = v6[];
    using v8 = v7&&;
    using v9 = v8&;
}

#endif
