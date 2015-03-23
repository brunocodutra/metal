// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_ASSERT_HPP
#define BOOST_MPL2_CORE_ASSERT_HPP

#include <boost/mpl2/core/detail/type.hpp>

#include <boost/static_assert.hpp>

#define BOOST_MPL2_ASSERT(PRED) \
    BOOST_STATIC_ASSERT(BOOST_MPL2_DETAIL_TYPE(PRED)::value)

#define BOOST_MPL2_ASSERT_MSG(PRED, MSG) \
    BOOST_STATIC_ASSERT_MSG(BOOST_MPL2_DETAIL_TYPE(PRED)::value, MSG)

#endif
