// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_DETAIL_LOOKUP_HPP
#define METAL_DETAIL_LOOKUP_HPP

#include <metal/list/list.hpp>
#include <metal/list/indices.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>

#include <metal/detail/declptr.hpp>

#if defined(__has_builtin)
#   if __has_builtin(__type_pack_element)
#       define METAL_USE_BUILTIN_TYPE_PACK_ELEMENT
#   endif
#endif

namespace metal
{
    namespace detail
    {
        template<typename, typename>
        struct entry {};

        template<typename, typename>
        struct entries;

        template<typename... keys, typename... vals>
        struct entries<list<keys...>, list<vals...>> :
            entry<keys, vals>...
        {};

        template<typename key, typename val>
        value<val> _lookup_impl(entry<key, val>*);

        template<typename>
        value<> _lookup_impl(...);

        template<typename vals, typename keys, typename key>
        struct _lookup :
            decltype(_lookup_impl<key>(declptr<entries<keys, vals>>()))
        {};

#if defined(METAL_USE_BUILTIN_TYPE_PACK_ELEMENT)
        template<typename>
        struct hash
        {};

        template<typename... vals>
        struct hash<list<vals...>>
        {
            template<typename, typename = true_>
            struct at
            {};

            template<int_ n>
            struct at<number<n>,
                number<(n >= 0 && n < sizeof...(vals))>
            >
            {
                using type = __type_pack_element<n, vals...>;
            };
        };

        template<typename vals, typename key>
        struct _lookup<vals, indices<vals>, key> :
            hash<vals>::template at<key>
        {};
#endif

        template<typename>
        struct _lookup_first
        {};

        template<typename x, typename... tail>
        struct _lookup_first<list<x, tail...>>
        {
            using type = x;
        };

        template<typename vals>
        struct _lookup<vals, indices<vals>, number<0>> :
            _lookup_first<vals>
        {};

        template<typename>
        struct _lookup_second
        {};

        template<typename x, typename y, typename... tail>
        struct _lookup_second<list<x, y, tail...>>
        {
            using type = y;
        };

        template<typename vals>
        struct _lookup<vals, indices<vals>, number<1>> :
            _lookup_second<vals>
        {};

        template<typename vals, typename keys, typename key>
        using lookup = typename _lookup<vals, keys, key>::type;
    }
}

#endif

