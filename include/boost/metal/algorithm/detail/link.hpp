// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_ALGORITHM_DETAIL_LINK_HPP
#define BOOST_METAL_ALGORITHM_DETAIL_LINK_HPP

#include <boost/metal/algebra/arithmetic/inc.hpp>
#include <boost/metal/algorithm/size.hpp>
#include <boost/metal/algorithm/detail/ref.hpp>

#include <type_traits>

namespace boost
{
    namespace metal
    {
        namespace detail
        {
            struct nil
            {
            protected:
                static ref<> item(...);

            public:
                using type = nil;

                using size = std::integral_constant<std::size_t, 0U>;

                template<typename i>
                struct at
                {};
            };

            template<typename index, typename value, typename rest>
            struct link :
                    rest
            {
            protected:
                static ref<value> item(ref<index>);
                using rest::item;

            public:
                using type = link;

                using size = inc< ::boost::metal::size<rest>>;

                template<typename i>
                struct at;
            };

            template<typename index, typename value, typename rest>
            template<typename i>
            struct link<index, value, rest>::at :
                    decltype(item(ref<i>{}))
            {};
        }
    }
}

#endif
