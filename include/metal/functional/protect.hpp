// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_PROTECT_HPP
#define METAL_FUNCTIONAL_PROTECT_HPP

#include <metal/functional/maybe.hpp>

namespace metal
{
    namespace detail
    {
        template<typename value, int = 0>
        struct protect_impl :
                maybe<value>
        {};
    }

    template<typename opt>
    using protect = detail::protect_impl<opt>;
}

#endif
