// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_TAG_HPP
#define BOOST_MPL2_SEQUENCES_TAG_HPP

#include <boost/mpl2/core/traits_factory.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        template<typename x>
        struct tag
        {
        private:
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_tag, tag);

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
}

#endif
