// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_VALUES_HPP
#define METAL_TEST_VALUES_HPP

namespace test
{
    enum val0 {type};
    union val1 {};
    using val2 = val1();
    using val3 = val2* const;
    using val4 = val2* volatile;
    using val5 = val3 volatile;
    using val6 = val5[1];
    using val7 = val6[];
    using val8 = val7&&;
    using val9 = val8&;
}

#endif
