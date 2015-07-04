/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_CORE_ASSERT_HPP
#define METAL_CORE_ASSERT_HPP

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

#define METAL_DETAIL_STRIP_PARENTHESIS(x) \
    metal::detail::strip_parenthesis<void x>

#define METAL_ASSERT_MSG(PRED, MSG) \
    static_assert(METAL_DETAIL_STRIP_PARENTHESIS(PRED)::value, MSG)

#define METAL_ASSERT(PRED) \
    METAL_ASSERT_MSG(PRED, #PRED)

#define METAL_ASSERT_EXPR_MSG(EXPR, MSG) \
    static_assert(EXPR, MSG)

#define METAL_ASSERT_EXPR(EXPR) \
    static_assert(EXPR, #EXPR)

#endif
