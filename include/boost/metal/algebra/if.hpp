/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_ALGEBRA_IF_HPP
#define BOOST_METAL_ALGEBRA_IF_HPP

#include <tuple>
#include <type_traits>

namespace boost
{
    namespace metal
    {
        template<typename pred, typename then, typename... else_>
        struct if_;

        template<typename pred1, typename then1, typename pred2, typename then2, typename... else_>
        struct if_<pred1, then1, pred2, then2, else_...> :
                if_<pred1, then1, if_<pred2, then2, else_...>>
        {};

        template<typename pred, typename then, typename else_>
        struct if_<pred, then, else_> :
                std::conditional<!!pred::value, then, else_>::type
        {};

        template<typename pred, typename then>
        struct if_<pred, then> :
                if_<pred, then, std::tuple<>>
        {};

        template<typename pred, typename then, typename... else_>
        using if_t = typename if_<pred, then, else_...>::type;
    }
}

#endif
