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
        struct tag;

        namespace detail
        {
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_tag, tag);

            template<typename x, typename = typename has_tag<x>::type>
            struct tag_impl
            {
                using type = typename x::tag;
            };

            template<typename x>
            struct tag_impl<x, std::false_type>
            {
                using type = ::boost::mpl2::tag<x>;
            };
        }

        template<typename x>
        struct tag :
                detail::tag_impl<x>
        {};
    }
}

#endif
