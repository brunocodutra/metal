// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ERASE_HPP
#define METAL_LIST_ERASE_HPP

#include <metal/number/number.hpp>

namespace metal
{
    /// \ingroup list
    /// ...
    template<typename...>
    struct erase
    {};

    /// \ingroup list
    /// Eager adaptor for \ref erase.
    template<typename... _>
    using erase_t = typename metal::erase<_...>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/inc.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    template<typename list, typename begin, begin b, typename end, end e>
    struct erase<list, number<begin, b>, number<end, e>> :
        conditional<
            boolean<(e >= b)>,
            invoke<
                copy<
                    _1,
                    join<
                        copy<_2, _1, integer<0>, number<begin, b>>,
                        copy<_2, _1, number<end, e>, size<_1>>
                    >
                >,
                list, metal::list<>
            >
        >
    {};

    template<typename list, typename begin, begin b>
    struct erase<list, number<begin, b>> :
        invoke<erase<quote_t<list>, number<begin, b>, inc_t<number<begin, b>>>>
    {};
}

#endif
