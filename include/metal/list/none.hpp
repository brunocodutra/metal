// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_NONE_HPP
#define METAL_LIST_NONE_HPP

#include <metal/list/any.hpp>
#include <metal/number/not.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename lbd>
    using none = metal::not_<metal::any<seq, lbd>>;
}

#endif
