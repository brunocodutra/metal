// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REMOVE_IF_HPP
#define METAL_LIST_REMOVE_IF_HPP

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    struct remove_if;

    /// \ingroup list
    /// Eager adaptor for \ref remove_if.
    template<typename list, typename lbd>
    using remove_if_t = typename metal::remove_if<list, lbd>::type;
}

#include <metal/list/copy_if.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    template<typename list, typename lbd>
    struct remove_if :
        copy_if<list, list, not_<lbd>>
    {};
}

#endif
