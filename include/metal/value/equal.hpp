// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_EQUAL_HPP
#define METAL_VALUE_EQUAL_HPP

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct _equal;
    }

    /// \ingroup list
    /// ...
    template<typename x, typename y>
    using equal = typename detail::_equal<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct _equal :
            false_
        {};

        template<typename x>
        struct _equal<x, x> :
            true_
        {};
    }
}

#endif
