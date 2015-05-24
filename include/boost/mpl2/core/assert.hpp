// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_ASSERT_HPP
#define BOOST_MPL2_CORE_ASSERT_HPP

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename>
            struct strip_parenthesis;

            template<typename x>
            struct strip_parenthesis<void(x)> :
                x
            {};
        }
    }
}

#define BOOST_MPL2_DETAIL_STRIP_PARENTHESIS(x) \
    boost::mpl2::detail::strip_parenthesis<void (x)>

#define BOOST_MPL2_ASSERT_MSG(PRED, MSG) \
    static_assert(BOOST_MPL2_DETAIL_STRIP_PARENTHESIS(PRED)::value, MSG)

#define BOOST_MPL2_ASSERT(PRED) \
    BOOST_MPL2_ASSERT_MSG(PRED, #PRED)

#define BOOST_MPL2_ASSERT_EXPR_MSG(EXPR, MSG) \
    static_assert(EXPR, MSG)

#define BOOST_MPL2_ASSERT_EXPR(EXPR) \
    static_assert(EXPR, #EXPR)

#endif
