// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_PUSH_BACK_HPP
#define METAL_LIST_PUSH_BACK_HPP

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/lambda.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename val>
    using push_back = copy<seq, join<apply<lambda<list>, seq>, list<val>>>;
}

#endif
