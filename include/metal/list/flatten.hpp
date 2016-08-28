// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_FLATTEN_HPP
#define METAL_LIST_FLATTEN_HPP

#include <metal/config.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _flatten;
    }

    /// \ingroup list
    /// ...
    template<typename seq>
    using flatten = typename detail::_flatten<seq>::type;
}

#include <metal/list/list.hpp>
#include <metal/list/join.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _flatten
        {};

        template<typename... vals>
        struct _flatten<list<vals...>> :
            _join<flatten<list<vals>>...>
        {};

        template<typename... vals>
        struct _flatten<list<list<vals...>>> :
            _flatten<list<vals...>>
        {};

        template<typename val>
        struct _flatten<list<val>>
        {
            using type = list<val>;
        };

        template<>
        struct _flatten<list<>>
        {
            using type = list<>;
        };
    }
}

#endif
