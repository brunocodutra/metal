// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_ERASE_HPP
#define METAL_LIST_ERASE_HPP

#include <metal/detail/nil.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename = nil>
        struct erase;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename beg, typename end = detail::nil>
    using erase = detail::erase<list, beg, end>;

    /// \ingroup list
    /// Eager adaptor for metal::erase.
    template<typename list, typename beg, typename end = detail::nil>
    using erase_t = typename metal::erase<list, beg, end>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/join.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/clear.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/number.hpp>
#include <metal/number/arithmetic/inc.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename = boolean<true>>
        struct erase_impl
        {};

        template<typename list, typename beg, beg b, typename end, end e>
        struct erase_impl<list, number<beg, b>, number<end, e>,
            boolean<(b <= e)>
        > :
            invoke<
                copy<quote_t<list>, lift_t<lambda<join>>>,
                copy<metal::list<>, list, integer<0>, number<beg, b>>,
                copy<metal::list<>, list, number<end, e>>
            >
        {};

        template<typename list, typename beg, beg b, typename end, end e>
        struct erase_impl<list, number<beg, b>, number<end, e>,
            boolean<(e < b)>
        > :
            erase_impl<list, number<end, e>, number<beg, b>>
        {};

        template<typename list, typename beg, typename end>
        struct erase :
            erase_impl<list, beg, end>
        {};

        template<typename list, typename beg, beg b, typename end>
        struct erase<list, number<beg, b>, number<end, end(b)>>
        {
            using type = list;
        };

        template<typename list, typename beg, beg b>
        struct erase<list, number<beg, b>> :
            erase<list, number<beg, b>, inc_t<number<beg, b>>>
        {};
    }
}

#endif
