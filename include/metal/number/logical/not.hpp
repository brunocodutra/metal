// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_NOT_HPP
#define METAL_NUMBER_LOGICAL_NOT_HPP

#include <metal/number/logical/query.hpp>

#include <type_traits>

namespace metal
{
    template<typename number>
    struct not_ :
        std::integral_constant<bool, !query<number>::value>
    {};

    template<typename value>
    using not_t = typename not_<value>::type;
}

#endif
