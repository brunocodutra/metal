// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_COPY_IF_HPP
#define METAL_LIST_COPY_IF_HPP

#include <metal/config.hpp>

#include <metal/list/transform.hpp>

#include <metal/detail/pick.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq, typename lbd>
    using copy_if = detail::pick<seq, transform<lbd, seq>>;
}

#endif
