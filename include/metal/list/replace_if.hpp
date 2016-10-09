// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP

#include <metal/config.hpp>

#include <metal/list/transform.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename, typename, typename>
        struct _replace_if_impl;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename lbd, typename val>
    using replace_if =
        typename detail::_replace_if_impl<seq, transform<lbd, seq>, val>::type;
}

#include <metal/list/list.hpp>
#include <metal/number/if.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename, typename, typename>
        struct _replace_if_impl
        {};

        template<typename val>
        struct _replace_if_impl<list<>, list<>, val>
        {
            using type = list<>;
        };

        template<typename... vals, int_... vs, typename val>
        struct _replace_if_impl<list<vals...>, list<number<vs>...>, val>
        {
            using type = list<if_<number<vs>, val, vals>...>;
        };
    }
    /// \endcond
}

#endif
