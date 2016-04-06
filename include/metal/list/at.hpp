// Copyright Bruno Dutra 2015-2016
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
    /// Eager adaptor for metal::at.
    template<typename list, typename n>
    using at_t = typename metal::at<list, n>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/front.hpp>
#include <metal/list/back.hpp>
#include <metal/list/size.hpp>
#include <metal/list/indices.hpp>
#include <metal/number/number.hpp>

#include <metal/detail/lookup.hpp>

#include <cstddef>

namespace metal
{
    namespace detail
    {
        template<typename list, typename n, typename = boolean<true>>
        struct at_impl
        {};

        template<typename list, typename t, t v>
        struct at_impl<list, number<t, v>,
            boolean<(0 < v) && (v < size_t<list>::value - 1)>
        > :
            lookup<indices_t<list>, list, number<std::size_t, v>>
        {};

        template<typename list, typename t>
        struct at_impl<list, number<t, t(0)>,
            boolean<(size_t<list>::value > 0)>
        > :
            front<list>
        {};

        template<typename list, typename t>
        struct at_impl<list, number<t, t(size_t<list>::value - 1)>,
            boolean<(size_t<list>::value > 1)>
        > :
            back<list>
        {};

        template<typename list, typename n>
        struct at :
            at_impl<list, n>
        {};
    }
}

#endif
