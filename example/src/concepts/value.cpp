// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include "example.hpp"

ANONYMOUS
{
/// [ex1]
using val = int;
/// [ex1]
}

ANONYMOUS
{
/// [ex2]
using val = decltype(3.14);
/// [ex2]
}

ANONYMOUS
{
/// [ex3]
struct val
{
    //...
};
/// [ex3]
}
