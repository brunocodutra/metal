/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_ALGORITHM_TAG_HPP
#define METAL_ALGORITHM_TAG_HPP

#include <metal/core/introspection.hpp>

#include <type_traits>

namespace metal
{
    template<typename x>
    struct tag
    {
    private:
        METAL_DEFINE_NESTED_TYPE_TRAIT(has_tag, tag);

        template<typename y, typename = has_tag_t<y>>
        struct impl
        {
            using type = typename y::tag;
        };

        template<typename y>
        struct impl<y, std::false_type>
        {
            using type = tag;
        };

    public:
        using type = typename impl<x>::type;
    };

    template<typename x>
    using tag_t = typename tag<x>::type;
}

#endif
