// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FIND_IF_HPP
#define METAL_LIST_FIND_IF_HPP

#include <metal/config.hpp>

#include <metal/list/transform.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _find_if_impl;
    }

    /// \ingroup list
    /// ...
    template<typename seq, typename lbd>
    using find_if = typename detail::_find_if_impl<transform<lbd, seq>>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/front.hpp>
#include <metal/list/flatten.hpp>
#include <metal/list/indices.hpp>
#include <metal/number/number.hpp>
#include <metal/number/if.hpp>

#include <initializer_list>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _find_if_impl
        {};

        template<>
        struct _find_if_impl<list<>> :
            number<0>
        {};

#if defined(METAL_COMPAT_MODE)
        template<typename seq, typename = indices<seq>>
        struct _find_index
        {};

        template<int_... vs, typename... is>
        struct _find_index<list<number<vs>...>, list<is...>>
        {
            using type = front<
                flatten<list<if_<number<vs>, is, list<>>..., size<list<is...>>>>
            >;
        };

        template<int_... vs>
        struct _find_if_impl<list<number<vs>...>> :
            _find_index<list<number<vs>...>>
        {};
#else
        template<typename... _>
        constexpr int_ find_index(_... vs) {
            int_ ret = 0;
            for(int_ x : std::initializer_list<int_>{vs...})
                if(x) break;
                else ++ret;

            return ret;
        }

        template<int_... vs>
        struct _find_if_impl<list<number<vs>...>> :
            number<find_index(vs...)>
        {};
#endif
    }
}

#endif
