// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_CORE_VOIDER_HPP
#define METAL_CORE_VOIDER_HPP

namespace metal
{
    /// \ingroup core
    /// ...
    template<typename...>
    struct voider;

    /// \ingroup core
    /// Eager adaptor for \ref voider.
    template<typename... _>
    using voider_t = typename metal::voider<_...>::type;

    template<typename...>
    struct voider
    {
        using type = void;
    };
}

#endif

