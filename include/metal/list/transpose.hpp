// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_TRANSPOSE_HPP
#define METAL_LIST_TRANSPOSE_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list>
    struct transpose;

    /// \ingroup list
    /// \brief Eager adaptor for \ref transpose.
    template<typename list>
    using transpose_t = typename transpose<list>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/same.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename = boolean<true>>
        struct transpose_impl
        {};

        template<
            template<typename...> class outer,
            typename head, typename... tail,
            typename _
        >
        struct transpose_impl<outer<head, tail...>, _> :
            transform<
                indices_t<head>,
                defer_t<outer<at<quote_t<head>, _1>, at<quote_t<tail>, _1>...>>
            >
        {};

        template<
            template<typename...> class outer,
            template<typename...> class xl, typename... xs,
            template<typename...> class yl, typename... ys
        >
        struct transpose_impl<outer<xl<xs...>, yl<ys...>>,
            boolean<sizeof...(xs) ==  sizeof...(ys)>
        >
        {
            using type = xl<outer<xs, ys>...>;
        };

        template<
            template<typename...> class outer,
            template<typename...> class inner,
            typename... vals
        >
        struct transpose_impl<outer<inner<vals...>>>
        {
            using type = inner<outer<vals>...>;
        };
    }

    template<typename list>
    struct transpose :
        detail::transpose_impl<list>
    {};
}

#endif
