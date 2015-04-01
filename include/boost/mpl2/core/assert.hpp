// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_ASSERT_HPP
#define BOOST_MPL2_CORE_ASSERT_HPP

#include <boost/mpl2/core/detail/strip_parenthesis.hpp>

#define BOOST_MPL2_ASSERT_MSG(PRED, MSG) \
    static_assert(BOOST_MPL2_DETAIL_STRIP_PARENTHESIS(PRED)::value, MSG)

#define BOOST_MPL2_ASSERT(PRED) \
    BOOST_MPL2_ASSERT_MSG(PRED, #PRED)

#endif
