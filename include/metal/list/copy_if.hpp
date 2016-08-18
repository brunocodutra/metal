// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COPY_IF_HPP
#define METAL_LIST_COPY_IF_HPP

#include <metal/list/transform.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename>
        struct _copy_if_impl;
    }

    /// \ingroup list
    /// ...
    template<typename seq, typename lbd>
    using copy_if =
        typename detail::_copy_if_impl<seq, transform<lbd, seq>>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>
#include <metal/number/if.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename>
        struct _copy_if_impl
        {};

        template<>
        struct _copy_if_impl<list<>, list<>>
        {
            using type = list<>;
        };

        template<typename... vals, int_... vs>
        struct _copy_if_impl<list<vals...>, list<number<vs>...>> :
            _join<if_<number<vs>, list<vals>, list<>>...>
        {};
    }
}

#endif
