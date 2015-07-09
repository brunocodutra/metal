// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_VERBATIM_HPP
#define METAL_FUNCTIONAL_VERBATIM_HPP

namespace metal
{
    namespace detail
    {
        template<typename, int = 0>
        struct verbatim_impl
        {
            using type = verbatim_impl;
        };
    }

    template<typename atom>
    using verbatim = detail::verbatim_impl<atom>;
}

#endif
