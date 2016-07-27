// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_APPLY_HPP
#define METAL_LAMBDA_APPLY_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename seq>
        struct _apply;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd, typename seq>
    using apply = typename detail::_apply<lbd, seq>::type;
}

#include <metal/lambda/invoke.hpp>

namespace metal
{
    namespace detail
    {
        template<typename lbd, typename seq>
        struct _apply
        {};

        template<
            typename lbd,
            template<typename...> class seq, typename... vals
        >
        struct _apply<lbd, seq<vals...>> :
            _invoke<lbd, vals...>
        {};
    }
}

#endif

