// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_NUMBER_HPP
#define METAL_NUMBER_NUMBER_HPP

#include <type_traits>

namespace metal
{
    template<typename type, type value>
    using number = std::integral_constant<type, value>;

    template<bool value>
    using boolean = std::integral_constant<bool, value>;
}

#endif
