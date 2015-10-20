// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_CLEAR_HPP
#define METAL_LIST_CLEAR_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct clear;

    /// \ingroup list
    /// \brief Eager adaptor for \ref clear.
    template<typename list>
    using clear_t = typename metal::clear<list>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/swap.hpp>

namespace metal
{
    template<typename list>
    struct clear :
        swap<list, metal::list<>>
    {};
}

#endif
