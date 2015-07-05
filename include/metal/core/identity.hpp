// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_CORE_IDENTITY_HPP
#define METAL_CORE_IDENTITY_HPP

namespace metal
{
    template<typename x>
    struct identity
    {
        using type = x;
    };

    template<typename x>
    using identity_t = typename identity<x>::type;
}

#endif
