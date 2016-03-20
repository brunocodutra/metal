// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_FIND_IF_HPP
#define METAL_LIST_FIND_IF_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd>
        struct find_if;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename lbd>
    using find_if = detail::find_if<list, lbd>;

    /// \ingroup list
    /// Eager adaptor for \ref find_if.
    template<typename list, typename lbd>
    using find_if_t = typename metal::find_if<list, lbd>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/any.hpp>
#include <metal/list/none.hpp>
#include <metal/list/copy_if.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/front.hpp>
#include <metal/list/size.hpp>
#include <metal/list/transpose.hpp>
#include <metal/pair/first.hpp>
#include <metal/pair/second.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/bind.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename lbd, typename = boolean<true>>
        struct find_if_impl
        {};

        template<typename list, typename lbd>
        struct find_if_impl<list, lbd, none_t<list, lbd>> :
            size<list>
        {};

        template<typename list, typename lbd>
        struct find_if_impl<list, lbd, any_t<list, lbd>> :
            first<
                front_t<
                    copy_if_t<
                        metal::list<>,
                        transpose_t<pair<indices_t<list>, list>>,
                        bind_t<lbd, second<_1>>
                    >
                >
            >
        {};

        template<typename list, typename lbd>
        struct find_if :
            find_if_impl<list, lbd>
        {};
    }
}

#endif
