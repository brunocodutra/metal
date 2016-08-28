// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_PREPEND_HPP
#define METAL_LIST_PREPEND_HPP

#include <metal/config.hpp>

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename head, typename... tail>
    using prepend = metal::join<metal::list<head, tail...>, seq>;
}

#endif
