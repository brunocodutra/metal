// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_ALGORITHM_LIST_HPP
#define BOOST_MPL2_ALGORITHM_LIST_HPP

#include <boost/mpl2/algorithm/detail/link.hpp>

#include <type_traits>
#include <cstddef>

namespace boost
{
    namespace mpl2
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
}

#endif
