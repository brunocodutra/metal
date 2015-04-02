// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_VOID_HPP
#define BOOST_MPL2_CORE_VOID_HPP

#include <boost/mpl2/integrals/logical/not.hpp>
#include <boost/mpl2/core/identity.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        struct void_ :
                identity<void_>
        {};

        template<typename x>
        using is_void_ = std::is_same<x, void_>;
    }
}

#endif
