// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_DETAIL_VOID_HPP
#define METAL_DETAIL_VOID_HPP

namespace metal
{
    namespace detail
    {
        template<typename>
        struct void_
        {
            using type = void;
        };

        template<typename _>
        using void_t = typename void_<_>::type;
    }
}

#endif
