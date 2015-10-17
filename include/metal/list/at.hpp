// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_AT_HPP
#define METAL_LIST_AT_HPP

namespace metal
{
    /// \ingroup list
    /// \brief ...
    template<typename list, typename val>
    struct at
    {};

    /// \ingroup list
    /// \brief Eager adaptor for \ref at.
    template<typename list, typename val>
    using at_t = typename at<list, val>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/size.hpp>
#include <metal/list/transpose.hpp>
#include <metal/map/at_key.hpp>
#include <metal/number/number.hpp>
#include <metal/number/enumerate.hpp>

#include <cstddef>

namespace metal
{
    template<
        template<typename...> class list,
        typename... vals,
        typename t, t v
    >
    struct at<list<vals...>, number<t, v>> :
        at_key<
            transpose_t<
                metal::list<
                    enumerate_t<size_t<list<vals...>>>,
                    list<vals...>
                >
            >,
            number<std::size_t, static_cast<std::size_t>(v)>
        >
    {};
}

#endif
