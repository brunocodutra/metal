// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_DETAIL_IS_SAME_HPP
#define METAL_DETAIL_IS_SAME_HPP

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        using is_same = typename std::is_same<x, y>::type;
    }
}

#endif

