// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_EXAMPLE_HPP
#define METAL_EXAMPLE_HPP

#include <type_traits>

#define CAT_IMPL(X, Y) X##Y
#define CAT(X, Y) CAT_IMPL(X, Y)

#define HIDE(...) struct CAT(anonymous, __LINE__) {__VA_ARGS__};

int main() {
    return 0;
}

#endif
