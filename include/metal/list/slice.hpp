// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SLICE_HPP
#define METAL_LIST_SLICE_HPP

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/if.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<
        typename seq,
        typename start, typename size, typename stride = int_<1>
    >
    using slice = transform<
        partial<lambda<at>, if_<is_list<seq>, seq>>,
        enumerate<start, size, stride>
    >;
}

#endif
