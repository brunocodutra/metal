// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_EXAMPLE_HPP
#define METAL_EXAMPLE_HPP

#include <initializer_list>

#define CAT_(X, Y) X##Y
#define CAT(X, Y) CAT_(X, Y)

#define ANONYMOUS(SCOPE) SCOPE CAT(anonymous, __LINE__)

int main()
{
    return 0;
}

#endif
