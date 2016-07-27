// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_ALL_HPP
#define METAL_LIST_ALL_HPP

#include <metal/list/transform.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/and.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename lbd>
    using all =
        metal::apply<metal::lambda<metal::and_>, metal::transform<lbd, seq>>;
}

#endif
