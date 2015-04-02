// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP
#define BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP

#include <boost/mpl2/integrals/size_t.hpp>
#include <boost/mpl2/integrals/arithmetic/inc.hpp>
#include <boost/mpl2/core/ref.hpp>

#include <utility>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            struct nil
            {
                typedef size_t_<0U> size;
                static ref<> item(ref<>);
                template<typename i>
                struct at;
            };

            template<typename index, typename value, typename rest>
            struct link :
                    rest
            {
                typedef inc<typename rest::size> size;

                static ref<value> item(ref<index>&&);
                using rest::item;

                template<typename i>
                struct at;
            };

            template<typename index, typename value, typename rest>
            template<typename i>
            struct link<index, value, rest>::at :
                    decltype(item(std::declval<ref<i> >()))
            {};

        }
    }
}

#endif
