// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_TRANSPOSE_HPP
#define METAL_LIST_TRANSPOSE_HPP

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename = true_, typename = true_, typename = true_>
        struct _transpose;
    }

    /// \ingroup list
    /// ...
    template<typename seq>
    using transpose = typename detail::_transpose<seq>::type;
}

#include <metal/list/at.hpp>
#include <metal/list/size.hpp>
#include <metal/list/same.hpp>
#include <metal/list/unwrap.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/greater.hpp>
#include <metal/value/equal.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename, typename>
        struct _transpose
        {};

        template<
            template<typename...> class outer,
            typename head, typename... tail
        >
        struct _transpose<outer<head, tail...>,
            greater<size<outer<head, tail...>>, size_t<2>>,
            same<outer<size<head>, size<tail>...>>,
            same<outer<unwrap<head>, unwrap<tail>...>>
        > :
            _transform<
                bind<
                    lambda<outer>,
                    partial<lambda<at>, head>,
                    partial<lambda<at>, tail>...
                >,
                indices<head>
            >
        {};

        template<
            template<typename...> class outer,
            template<typename...> class inner,
            typename... xs, typename... ys
        >
        struct _transpose<outer<inner<xs...>, inner<ys...>>,
            equal<size<outer<inner<xs...>, inner<ys...>>>, size_t<2>>,
            equal<size<inner<xs...>>, size<inner<ys...>>>
        >
        {
            using type = inner<outer<xs, ys>...>;
        };

        template<
            template<typename...> class outer,
            template<typename...> class inner,
            typename... xs
        >
        struct _transpose<outer<inner<xs...>>,
            equal<size<outer<inner<xs...>>>, size_t<1>>
        >
        {
            using type = inner<outer<xs>...>;
        };
    }
}

#endif
