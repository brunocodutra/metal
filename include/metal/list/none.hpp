// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_NONE_HPP
#define METAL_LIST_NONE_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct none;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using none = detail::none<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for \ref none.
    template<typename list, typename lbd>
    using none_t = typename metal::none<list, lbd>::type;
}

#include <metal/list/any.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct none :
            invoke<not_<lambda<any>>, list, lbd>
        {};
    }
}

#endif
