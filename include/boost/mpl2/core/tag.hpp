// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_TAG_HPP
#define BOOST_MPL2_CORE_TAG_HPP

#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/integrals/boolean.hpp>
#include <boost/mpl2/core/nested_type_trait.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_tag, tag);

            template<typename type, typename = typename has_tag<type>::type>
            struct tag;

            template<typename tagged>
            struct tag<tagged, false_>:
                    identity<tag<tagged> >
            {};

            template<typename tagged>
            struct tag<tagged, true_> :
                    identity<typename tagged::tag>
            {};
        }

        template<typename type>
        struct tag :
                detail::tag<type>
        {};
    }
}

#endif
