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
    namespace detail
    {
        template<typename list, typename lbd>
        struct find_if;

        template<
            template<typename...> class expr,
            typename... vals, typename lbd
        >
        struct find_if<expr<vals...>, lbd> :
            invoke<
                first<
                    front<
                        conditional<
                            empty<copy_if<_1, _2, _3>>,
                            list<pair<size<_2>, nil>>,
                            copy_if<_1, _2, _3>
                        >
                    >
                >,
                metal::list<>,
                transpose_t<pair<indices_t<expr<vals...>>, expr<vals...>>>,
                bind_t<lbd, second<_1>>
            >
        {};
    }
}

#endif
