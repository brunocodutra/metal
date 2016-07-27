// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_DETAIL_LOOKUP_HPP
#define METAL_DETAIL_LOOKUP_HPP

#include <metal/detail/nil.hpp>
#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename val>
        struct entry
        {
            using type = val;
        };

        template<typename key, typename val>
        entry<key, val> _lookup_impl(entry<key, val>*);

        template<typename>
        nil _lookup_impl(...);

        template<typename, typename>
        struct hash;

        template<
            template<typename...> class seq,
            typename... keys, typename... vals
        >
        struct hash<seq<keys...>, seq<vals...>> :
            entry<keys, vals>...
        {};

        template<typename keys, typename vals, typename key>
        struct _lookup :
            decltype(_lookup_impl<key>(declptr<hash<keys, vals>>()))
        {};

        template<typename keys, typename vals, typename key>
        using lookup = typename _lookup<keys, vals, key>::type;
    }
}

#endif

