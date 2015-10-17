// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_OPTIONAL_HPP
#define METAL_OPTIONAL_OPTIONAL_HPP

namespace metal
{
    namespace detail
    {
        struct nil;

        template<typename, typename, typename = void>
        struct optional_impl;
    }

    /// \ingroup optional
    /// \brief ...
    template<typename opt, typename fallback = detail::nil>
    using optional = typename detail::optional_impl<opt, fallback>::type;
}

#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>
#include <metal/core/voider.hpp>

namespace metal
{
    namespace detail
    {
        template<typename opt, typename fallback, typename>
        struct optional_impl
        {
            using type = just<fallback>;
        };

        template<typename opt, typename _>
        struct optional_impl<opt, nil, _>
        {
            using type = nothing;
        };

        template<typename opt, typename _>
        struct optional_impl<opt, _, voider_t<typename opt::type, int opt::*>>
        {
            using type = just<typename opt::type>;
        };
        
        template<typename opt>
        struct optional_impl<opt, nil, voider_t<typename opt::type, int opt::*>>
        {
            using type = just<typename opt::type>;
        };
    }
}

#endif
