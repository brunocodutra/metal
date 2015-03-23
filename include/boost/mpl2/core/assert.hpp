// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_ASSERT_HPP
#define BOOST_MPL2_CORE_ASSERT_HPP

#include <boost/mpl2/core/logical/not.hpp>

#include <boost/static_assert.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename>
            struct assert_;

            template<typename T>
            struct assert_<void (T)> : T {};
        }
    }
}

#define BOOST_MPL2_ASSERT(PRED) \
    BOOST_STATIC_ASSERT(boost::mpl2::detail::assert_<void (PRED)>::type::value)

#define BOOST_MPL2_ASSERT_NOT(PRED) \
    BOOST_STATIC_ASSERT(boost::mpl2::not_<boost::mpl2::detail::assert_<void (PRED)> >::type::value)

#define BOOST_MPL2_ASSERT_MSG(PRED, MSG) \
    BOOST_STATIC_ASSERT_MSG(boost::mpl2::detail::assert_<void (PRED)>::type::value, MSG)

#define BOOST_MPL2_ASSERT_MSG_NOT(PRED, MSG) \
    BOOST_STATIC_ASSERT_MSG(boost::mpl2::not_<boost::mpl2::detail::assert_<void (PRED)> >::type::value, MSG)

#define BOOST_MPL2_ASSERT_RELATION(X, OP, Y) \
    BOOST_STATIC_ASSERT(X OP Y)

#endif
