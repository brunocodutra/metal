// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_MAYBE_HPP
#define METAL_OPTIONAL_MAYBE_HPP

#include <metal/optional/just.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename opt>
    struct maybe;

    namespace detail
    {
        template<typename, typename = boolean<true>>
        struct maybe_impl
        {};

        template<typename opt>
        struct maybe_impl<opt, is_just_t<opt>> :
                just<typename opt::type>
        {};
    }

    template<typename opt>
    struct maybe :
            detail::maybe_impl<opt>
    {};
}

#endif
