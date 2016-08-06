// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP

#include <metal/list/indices.hpp>

#include <metal/detail/lookup.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename num>
    using at = detail::lookup<seq, indices<seq>, num>;
}

#endif
