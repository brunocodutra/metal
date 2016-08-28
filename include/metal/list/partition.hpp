// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_PARTITION_HPP
#define METAL_LIST_PARTITION_HPP

#include <metal/config.hpp>

#include <metal/list/copy_if.hpp>
#include <metal/list/remove_if.hpp>
#include <metal/pair/pair.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/not.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename lbd>
    using partition =
        metal::pair<metal::copy_if<seq, lbd>, metal::remove_if<seq, lbd>>;
}

#endif
