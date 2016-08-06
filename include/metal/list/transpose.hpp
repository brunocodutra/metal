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
        template<typename, typename = true_, typename = true_>
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
#include <metal/list/indices.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>

namespace metal
{
    namespace detail
    {
        template<typename, typename, typename>
        struct _transpose
        {};

        template<typename head, typename... tail>
        struct _transpose<list<head, tail...>,
            number<(sizeof...(tail) > 1)>,
            same<list<size<head>, size<tail>...>>
        > :
            _transform<
                bind<
                    lambda<list>,
                    partial<lambda<at>, head>,
                    partial<lambda<at>, tail>...
                >,
                indices<head>
            >
        {};

        template<typename... xs, typename... ys>
        struct _transpose<list<list<xs...>, list<ys...>>,
            number<sizeof...(xs) == sizeof...(ys)>
        >
        {
            using type = list<list<xs, ys>...>;
        };

        template<typename... xs>
        struct _transpose<list<list<xs...>>>
        {
            using type = list<list<xs>...>;
        };
    }
}

#endif
