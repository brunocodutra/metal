// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename idx>
    struct at;

    /// \ingroup list
    /// \brief Eager adaptor for \ref at.
    template<typename list, typename idx>
    using at_t = typename at<list, idx>::type;
}

#include <metal/list/indices.hpp>
#include <metal/list/list.hpp>
#include <metal/list/transpose.hpp>
#include <metal/map/at_key.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/conditional.hpp>
#include <metal/pair/pair.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename, typename>
        struct at_impl
        {};

        template<typename list, typename t, t v>
        struct at_impl<list, number<t, v>> :
            at_key<
                transpose_t<pair<indices_t<list>, list>>,
                number<std::size_t, static_cast<std::size_t>(v)>
            >
        {};
    }

    template<typename list, typename idx>
    struct at :
        conditional<is_list_t<list>, detail::at_impl<list, idx>>
    {};
}

#endif
