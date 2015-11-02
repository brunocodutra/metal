// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_FIND_IF_HPP
#define METAL_LIST_FIND_IF_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename lbd>
    struct find_if;

    /// \ingroup list
    /// \brief Eager adaptor for \ref find_if.
    template<typename list, typename lbd>
    using find_if_t = typename find_if<list, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy_if.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/front.hpp>
#include <metal/list/transpose.hpp>
#include <metal/pair/first.hpp>
#include <metal/pair/second.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/bind.hpp>

namespace metal
{
    template<typename list, typename lbd>
    struct find_if :
        invoke<
            first<front<copy_if<_1, transpose<pair<indices<_2>, _2>>, _3>>>,
            metal::list<>, list, bind_t<lbd, second<_1>>
        >
    {};
}

#endif
