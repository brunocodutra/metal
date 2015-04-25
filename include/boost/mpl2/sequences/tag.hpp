// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_TAG_HPP
#define BOOST_MPL2_SEQUENCES_TAG_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/detail/nested_type_trait.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename type>
        struct tag;

        namespace detail
        {
            BOOST_MPL2_DETAIL_DEFINE_NESTED_TYPE_TRAIT(has_tag, tag);

            template<typename type, typename = typename has_tag<type>::type>
            struct tag_impl;

            template<typename tagged>
            struct tag_impl<tagged, false_>
            {
                using type = tag<tagged>;
            };

            template<typename tagged>
            struct tag_impl<tagged, true_>
            {
                using type = typename tagged::tag;
            };
        }

        template<typename type>
        struct tag :
                detail::tag_impl<type>
        {};
    }
}

#endif
