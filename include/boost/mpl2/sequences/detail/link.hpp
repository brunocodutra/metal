/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#ifndef _BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP_
#define _BOOST_MPL2_SEQUENCES_DETAIL_LINK_HPP_

#include <boost/mpl2/config/options/decltype.hpp>
#include <boost/mpl2/compat/numbered.hpp>
#include <boost/mpl2/core/integral/size_t.hpp>
#include <boost/mpl2/core/arithmetic/inc.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/sequences/detail/ref.hpp>

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
#if !defined(BOOST_MPL2_CFG_NO_DECLTYPE)
                static BOOST_CONSTEXPR ref<> item(...);
#endif
            };

            template<typename index, typename value, typename rest>
            struct link :
                    rest::type
            {
                typedef inc<typename rest::size> size;

#if !defined(BOOST_MPL2_CFG_NO_DECLTYPE)
                static BOOST_CONSTEXPR ref<value> item(ref<index>);
                using rest::type::item;
#endif
                template<typename i, BOOST_MPL2_OPTIONAL_PARAMS(1, _)>
                struct at;
            };

#if defined(BOOST_MPL2_CFG_NO_DECLTYPE)
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
