// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FIND_IF_HPP
#define METAL_LIST_FIND_IF_HPP

#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/front.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/flatten.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename seq, typename lbd>
    using find_if = front<
        flatten<
            list<
                transform<
                    bind<lambda<if_>, _1, _2, quote<list<>>>,
                    transform<lbd, seq>,
                    indices<seq>
                >,
                size<seq>
            >
        >
    >;
}

#endif
