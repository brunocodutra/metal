// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SIZE_HPP
#define METAL_LIST_SIZE_HPP

#include <metal/config.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _size;
    }

    /// \ingroup list
    /// ...
    template<typename seq>
    using size = typename detail::_size<seq>::type;
}

#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename seq>
        struct _size
        {};

        template<typename... vals>
        struct _size<list<vals...>> :
            number<sizeof...(vals)>
        {};
    }
}

#endif
