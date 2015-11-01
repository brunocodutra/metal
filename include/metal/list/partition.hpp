// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_PARTITION_HPP
#define METAL_LIST_PARTITION_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename lbd>
    struct partition;

    /// \ingroup list
    /// \brief Eager adaptor for \ref partition.
    template<typename list, typename lbd>
    using partition_t = typename partition<list, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy_if.hpp>
#include <metal/pair/pair.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    template<typename list, typename lbd>
    struct partition :
        invoke<
            lift_t<lambda<pair>>,
            copy_if<list, list, lbd>,
            copy_if<list, list, not_<lbd>>
        >
    {};
}

#endif
