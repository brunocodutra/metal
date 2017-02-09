// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

#include <metal/config.hpp>

#include <metal/lambda/invoke.hpp>

namespace metal
{
    /// \ingroup lambda
    ///
    /// ### Description
    /// ...
    template<typename lbd, typename seq>
    using apply = typename detail::_invoke_impl<lbd, seq>::type;
}

#endif

