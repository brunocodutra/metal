// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_LOGICAL_OR_HPP
#define BOOST_MPL2_METAFUNCTIONAL_LOGICAL_OR_HPP

#include <boost/mpl2/core/integral.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename x, typename y, typename... _>
        struct or_ :
                or_<x, or_<y, _...> >
        {};

        template<typename x, typename y>
        struct or_<x, y> :
                or_<bool_<!!x::value>, y>
        {};

        template<typename y> struct or_<false_, y> : y {};
        template<typename y> struct or_<true_, y> : true_ {};
    }
}

#endif
