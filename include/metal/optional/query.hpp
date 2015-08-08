// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_QUERY_HPP
#define METAL_OPTIONAL_QUERY_HPP

#include <metal/number/number.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename opt>
    struct query;

    /// \ingroup optional
    /// \brief Eager adaptor for \ref query.
    template<typename opt>
    using query_t = typename query<opt>::type;

    namespace detail
    {
        template<typename opt, typename = boolean<false>>
        struct query_impl :
                boolean<false>
        {};

        template<typename opt>
        struct query_impl<opt, not_t<typename opt::type>> :
                boolean<true>
        {};
    }

    template<typename opt>
    struct query :
            detail::query_impl<opt>
    {};
}

#endif
