// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_REF_HPP
#define BOOST_MPL2_CORE_REF_HPP

#include <boost/mpl2/core/compat/numbered.hpp>
#include <boost/mpl2/core/identity.hpp>

namespace boost
{
    namespace mpl2
    {
        template<BOOST_MPL2_OPTIONAL_PARAMS(1, value)>
        struct ref :
                identity<BOOST_MPL2_ARGS(1, value)>
        {};

        //NULL
        template<>
        struct ref<>;
    }
}

#endif
