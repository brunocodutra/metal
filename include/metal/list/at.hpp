// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename n>
        struct at;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename n>
    using at = detail::at<list, n>;

    /// \ingroup list
    /// Eager adaptor for \ref at.
    template<typename list, typename n>
    using at_t = typename metal::at<list, n>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/front.hpp>
#include <metal/list/indices.hpp>
#include <metal/list/transpose.hpp>
#include <metal/map/at_key.hpp>
#include <metal/pair/pair.hpp>
#include <metal/number/number.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename list, typename n, typename = boolean<true>>
        struct at_impl
        {};

        template<typename list, typename n>
        struct at_impl<list, n, is_list_t<list>> :
            at_key<transpose_t<pair<indices_t<list>, list>>, n>
        {};

        template<typename list, typename n>
        struct at
        {};

        template<typename list, typename t, t v>
        struct at<list, number<t, v>> :
            at_impl<list, number<std::size_t, static_cast<std::size_t>(v)>>
        {};

        template<typename list, typename t>
        struct at<list, number<t, t(0)>> :
            front<list>
        {};
    }
}

#endif
