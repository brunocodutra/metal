// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_SEQUENCES_DETAIL_REF_HPP
#define BOOST_MPL2_SEQUENCES_DETAIL_REF_HPP

#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/sequences/detail/na.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename x = detail::na>
        struct ref :
                identity<x>
        {};

        //NULL
        template<>
        struct ref<>;
    }
}

#endif
