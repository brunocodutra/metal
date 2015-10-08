// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_OPTIONAL_HPP
#define METAL_OPTIONAL_OPTIONAL_HPP

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename opt>
    struct optional;
}

#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>
#include <metal/core/voider.hpp>

namespace metal
{
    namespace detail
    {
        template<typename opt, typename = void>
        struct optional_impl :
            nothing
        {};

        template<typename opt>
        struct optional_impl<opt, voider_t<typename opt::type, int opt::*>> :
            just<typename opt::type>
        {};
    }

    template<typename opt>
    struct optional :
        detail::optional_impl<opt>
    {};
}

#endif
