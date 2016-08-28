// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_EMPTY_HPP
#define METAL_LIST_EMPTY_HPP

#include <metal/config.hpp>

#include <metal/list/size.hpp>
#include <metal/number/not.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq>
    using empty = metal::not_<metal::size<seq>>;
}

#endif
