/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_CONTAINERS_HPP
#define METAL_TEST_CONTAINERS_HPP

#include "test/types.hpp"

namespace test
{
    template<template<typename...> class seq>
    using none = seq<>;

    template<template<typename...> class seq>
    using single = seq<a>;

    template<template<typename...> class seq>
    using many = seq<a, b, c, d, e, f, g, h, i, j>;
}

#endif

