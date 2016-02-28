// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_PARTITION_HPP
#define METAL_LIST_PARTITION_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct partition;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using partition = detail::partition<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for \ref partition.
    template<typename list, typename lbd>
    using partition_t = typename metal::partition<list, lbd>::type;
}

#include <metal/list/copy_if.hpp>
#include <metal/pair/pair.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/number/logical/not.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct partition :
            invoke<
                pair<copy_if<_1, _1, _2>, copy_if<_1, _1, _3>>,
                list, lbd, not_<lbd>
            >
        {};
    }
}

#endif
