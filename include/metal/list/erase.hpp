// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_ERASE_HPP
#define METAL_LIST_ERASE_HPP

#include <metal/list/join.hpp>
#include <metal/list/size.hpp>
#include <metal/list/range.hpp>
#include <metal/number/number.hpp>
#include <metal/number/min.hpp>
#include <metal/number/max.hpp>
#include <metal/number/inc.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename beg, typename end = inc<beg>>
    using erase = metal::join<
        metal::range<seq, metal::size_t<0>, metal::min<beg, end>>,
        metal::range<seq, metal::max<beg, end>, metal::size<seq>>
    >;
}

#endif
