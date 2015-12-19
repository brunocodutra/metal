// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [ex1]
using val = int;
/// [ex1]
}

ANONYMOUS(namespace)
{
/// [ex2]
using val = decltype(3.14);
/// [ex2]
}

ANONYMOUS(namespace)
{
/// [ex3]
struct val
{
    //...
};
/// [ex3]
}

ANONYMOUS(struct)
{
/// [nex1]
int val;
/// [nex1]
};

ANONYMOUS(struct)
{
static constexpr
/// [nex2]
auto val = 3.14;
/// [nex2]
};

ANONYMOUS(struct)
{
/// [nex3]
struct
{
    //...
} val;
/// [nex3]
};
