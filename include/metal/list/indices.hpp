// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_INDICES_HPP
#define METAL_LIST_INDICES_HPP

#include <metal/list/size.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq>
    using indices = metal::enumerate<metal::size_t<0>, metal::size<seq>>;
}

#endif
