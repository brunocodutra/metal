// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_QUERY_HPP
#define METAL_NUMBER_LOGICAL_QUERY_HPP

#include <metal/number/number.hpp>

namespace metal
{
    template<typename number>
    struct query;

    namespace detail
    {
        template<typename, typename = boolean<true>>
        struct query_impl :
                boolean<false>
        {};

        template<typename number>
        struct query_impl<number, boolean<!!number::value>> :
                boolean<true>
        {};
    }

    template<typename number>
    struct query :
            detail::query_impl<number>
    {};

    template<typename number>
    using query_t = typename query<number>::type;
}

#endif
