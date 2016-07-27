// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COPY_HPP
#define METAL_LIST_COPY_HPP

#include <metal/list/unwrap.hpp>
#include <metal/lambda/apply.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename to, typename from>
    using copy = metal::apply<metal::unwrap<to>, from>;
}

#endif
