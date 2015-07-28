// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_QUERY_HPP
#define METAL_NUMBER_LOGICAL_QUERY_HPP

#include <type_traits>

namespace metal
{
    template<typename number>
    struct query;

    namespace detail
    {
        template<typename, typename = std::true_type>
        struct query_impl :
                std::false_type
        {};

        template<typename number>
        struct query_impl<number, std::integral_constant<bool, !!number::value>> :
                std::true_type
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
