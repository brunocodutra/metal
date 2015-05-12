// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_LIST_HPP
#define BOOST_MPL2_SEQUENCES_LIST_HPP

#include <boost/mpl2/lambda/integral.hpp>
#include <boost/mpl2/sequences/detail/link.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename...>
        struct list;

        template<typename head, typename... tail>
        struct list<head, tail...> :
                detail::link<size_t_<sizeof...(tail)>, head, list<tail...> >
        {
            typedef list type;
        };

        template<>
        struct list<> :
                detail::nil
        {
            typedef list type;
        };
    }
}

#endif
