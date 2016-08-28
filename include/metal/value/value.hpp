// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_VALUE_VALUE_HPP
#define METAL_VALUE_VALUE_HPP

#include <metal/config.hpp>

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        struct na;

        template<typename val = na>
        struct value;
    }

    /// \ingroup value
    /// ...
    template<typename val = detail::na>
    using value = detail::value<val>;

    /// \ingroup value
    /// ...
    template<typename val>
    using is_value = metal::true_;

    namespace detail
    {
        template<typename val>
        struct value
        {
            using type = val;
        };

        template<>
        struct value<na> {};
    }
}

#endif

