// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_REPLACE_IF_HPP
#define METAL_LIST_REPLACE_IF_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd, typename val>
        struct replace_if;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd, typename val>
    using replace_if = detail::replace_if<list, lbd, val>;

    /// \ingroup list
    /// Eager adaptor for \ref replace_if.
    template<typename list, typename lbd, typename val>
    using replace_if_t = typename metal::replace_if<list, lbd, val>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/apply.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    namespace detail
    {
        template<
            typename list, typename lbd, typename val,
            typename = boolean<true>
        >
        struct replace_if_impl :
            invoke<
                copy<_1, apply<_2, transform<_3, _1>>>,
                list,
                lambda<join>,
                conditional<
                    bind_t<lbd, _1>,
                    quote_t<metal::list<val>>,
                    metal::list<_1>
                >
            >
        {};

        template<typename list, typename lbd, typename val>
        struct replace_if_impl<list, lbd, val, empty_t<list>>
        {
            using type = list;
        };

        template<typename list, typename lbd, typename val>
        struct replace_if :
            replace_if_impl<list, lbd, val>
        {};
    }
}

#endif
