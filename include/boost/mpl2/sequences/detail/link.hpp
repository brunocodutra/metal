// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP
#define BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP

#include <boost/mpl2/core/compat/numbered.hpp>
#include <boost/mpl2/core/integral/size_t.hpp>
#include <boost/mpl2/core/arithmetic/inc.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/ref.hpp>

#include <boost/config.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            struct nil
            {
                typedef size_t_<0U> size;
#if !defined(BOOST_NO_CXX11_DECLTYPE)
                static ref<> item(...);
#endif
            };

            template<typename index, typename value, typename rest>
            struct link :
                    rest
            {
                typedef inc<typename rest::size> size;

#if !defined(BOOST_NO_CXX11_DECLTYPE)
                static ref<value> item(ref<index>);
                using rest::item;
#endif
                template<typename i, BOOST_MPL2_OPTIONAL_PARAMS(1, _)>
                struct at;
            };

#if defined(BOOST_NO_CXX11_DECLTYPE)
            template<typename index, typename value, typename rest>
            template<typename i, typename _>
            struct link<index, value, rest>::at :
                    rest::template at<i>
            {};

            template<typename index, typename value, typename rest>
            template<typename _>
            struct link<index, value, rest>::at<index, _> :
                    identity<value>
            {};
#else
            template<typename index, typename value, typename rest>
            template<typename i, typename _>
            struct link<index, value, rest>::at :
                    decltype(item(ref<i>()))
            {};
#endif
        }
    }
}

#endif
