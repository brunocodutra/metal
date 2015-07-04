/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGORITHM_LIST_HPP
#define METAL_ALGORITHM_LIST_HPP

#include <metal/algorithm/detail/link.hpp>

#include <type_traits>
#include <cstddef>

namespace metal
{
    template<typename...>
    struct list :
            detail::nil
    {
        using type = list;
    };

    template<typename head, typename... tail>
    struct list<head, tail...> :
            detail::link<
                std::integral_constant<std::size_t, sizeof...(tail)>,
                head,
                list<tail...>
            >
    {
    private:
        using base = detail::link<
            std::integral_constant<std::size_t, sizeof...(tail)>,
            head,
            list<tail...>
        >;

    public:
        using type = list;

        template<typename i>
        struct at;
    };

    template<typename head, typename... tail>
    template<typename i>
    struct list<head, tail...>::at :
            list<head, tail...>::base::template at<
                std::integral_constant<
                    std::size_t,
                    sizeof...(tail) - i::value
                >
            >
    {};
}

#endif
