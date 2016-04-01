// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_DETAIL_LOOKUP_HPP
#define METAL_DETAIL_LOOKUP_HPP

#include <metal/optional/optional.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename>
        struct entry
        {};

        template<typename key, typename val>
        just<val> lookup_impl(entry<key, val>*);

        template<typename>
        nothing lookup_impl(...);

        template<typename, typename>
        struct hash;

        template<
            template<typename...> class expr,
            typename... keys, typename... vals
        >
        struct hash<expr<keys...>, expr<vals...>> :
            entry<keys, vals>...
        {};

        template<typename keys, typename vals, typename key>
        struct lookup :
            decltype(lookup_impl<key>(declptr<hash<keys, vals>>()))
        {};
    }
}

#endif

