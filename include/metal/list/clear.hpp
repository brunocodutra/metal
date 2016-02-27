// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_CLEAR_HPP
#define METAL_LIST_CLEAR_HPP

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct clear;
    }

    /// \ingroup list
    /// ...
    template<typename list>
    using clear = detail::clear<list>;

    /// \ingroup list
    /// Eager adaptor for \ref clear.
    template<typename list>
    using clear_t = typename metal::clear<list>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list>
        struct clear :
            copy<list, metal::list<>>
        {};
    }
}

#endif
