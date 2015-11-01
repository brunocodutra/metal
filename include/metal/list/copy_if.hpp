// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_COPY_IF_HPP
#define METAL_LIST_COPY_IF_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename to, typename from, typename lbd>
    struct copy_if;

    /// \ingroup list
    /// \brief Eager adaptor for \ref copy_if.
    template<typename to, typename from, typename lbd>
    using copy_if_t = typename copy_if<to, from, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/copy.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    template<typename to, template<typename...> class from, typename... fs, typename lbd>
    struct copy_if<to, from<fs...>, lbd> :
        invoke<
            lift_t<copy<quote_t<to>, lambda<join>>>,
            invoke<conditional<bind_t<lbd, _1>, list<_1>, list<>>, fs>...
        >
    {};
}

#endif
