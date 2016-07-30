// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_CAST_HPP
#define METAL_NUMBER_CAST_HPP

#include <metal/number/number.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename from, typename to, typename = to>
        struct _cast;
    }

    /// \ingroup number
    /// ...
    template<typename from, typename to>
    using cast = typename detail::_cast<from, to>::type;

    namespace detail
    {
        template<typename from, typename to, typename>
        struct _cast
        {};

        template<typename t, t v, typename to>
        struct _cast<number<t, v>, to,
            std::enable_if_t<
                std::is_integral<to>::value && !std::is_same<to, bool>::value,
                decltype(to{v})
            >
        > :
            number<to, v>
        {};

        template<typename t, t v>
        struct _cast<number<t, v>, bool> :
            bool_<v ? true : false>
        {};
    }
}

#endif
