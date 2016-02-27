// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include "example.hpp"

HIDDEN(namespace)
{
/// [ex1]
using val = int;
/// [ex1]
}

HIDDEN(namespace)
{
/// [ex2]
using val = decltype(3.14);
/// [ex2]
}

HIDDEN(namespace)
{
/// [ex3]
struct val
{
    //...
};
/// [ex3]
}

HIDDEN(struct)
{
/// [nex1]
int not_a_value;
/// [nex1]
};

HIDDEN(struct)
{
static constexpr
/// [nex2]
auto not_a_value = 3.14;
/// [nex2]
};

HIDDEN(struct)
{
/// [nex3]
struct
{
    //...
} not_a_value;
/// [nex3]
};
