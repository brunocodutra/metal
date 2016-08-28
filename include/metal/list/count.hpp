// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COUNT_HPP
#define METAL_LIST_COUNT_HPP

#include <metal/config.hpp>

#include <metal/list/count_if.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename val>
    using count =
        metal::count_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
