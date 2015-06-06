// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_LIST_HPP
#define BOOST_MPL2_SEQUENCES_LIST_HPP

#include <boost/mpl2/sequences/detail/link.hpp>

#include <type_traits>
#include <cstddef>

namespace boost
{
    namespace mpl2
    {
        template<typename...>
        struct list;

        template<typename head, typename... tail>
        struct list<head, tail...> :
                detail::link<
                    std::integral_constant<std::size_t, sizeof...(tail)>,
                    head,
                    list<tail...>
                >
        {
            using type = list;

            template<typename i>
            struct at;
        };

        template<typename head, typename... tail>
        template<typename i>
        struct list<head, tail...>::at :
                decltype(list::item(ref<
                    std::integral_constant<
                        std::size_t,
                        sizeof...(tail) - i::value
                    >
                >{}))
        {};

        template<>
        struct list<> :
                detail::nil
        {
            using type = list;
        };
    }
}

#endif
