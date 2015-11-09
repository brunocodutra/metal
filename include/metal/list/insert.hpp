// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_INSERT_HPP
#define METAL_LIST_INSERT_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list, typename n, typename val>
    struct insert;

    /// \ingroup list
    /// Eager adaptor for \ref insert.
    template<typename list, typename n, typename val>
    using insert_t = typename metal::insert<list, n, val>::type;
}

#include <metal/list/splice.hpp>
#include <metal/list/list.hpp>

namespace metal
{
    template<typename list, typename n, typename val>
    struct insert :
        splice<list, n, metal::list<val>>
    {};
}

#endif
