// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_LIST_HPP
#define METAL_LIST_LIST_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_list;

        template<typename... vals>
        struct list {};
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename val>
    using is_list = typename detail::_is_list<val>::type;

    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename... vals>
    using list = detail::list<vals...>;
}

#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_list :
            false_
        {};

        template<typename... vals>
        struct _is_list<list<vals...>> :
            true_
        {};
    }
    /// \endcond
}

#endif
