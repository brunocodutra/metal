/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_CORE_ASSERT_HPP
#define BOOST_METAL_CORE_ASSERT_HPP

namespace boost
{
    namespace metal
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

#define BOOST_METAL_DETAIL_STRIP_PARENTHESIS(x) \
    boost::metal::detail::strip_parenthesis<void x>

#define BOOST_METAL_ASSERT_MSG(PRED, MSG) \
    static_assert(BOOST_METAL_DETAIL_STRIP_PARENTHESIS(PRED)::value, MSG)

#define BOOST_METAL_ASSERT(PRED) \
    BOOST_METAL_ASSERT_MSG(PRED, #PRED)

#define BOOST_METAL_ASSERT_EXPR_MSG(EXPR, MSG) \
    static_assert(EXPR, MSG)

#define BOOST_METAL_ASSERT_EXPR(EXPR) \
    static_assert(EXPR, #EXPR)

#endif
