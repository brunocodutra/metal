// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_IF_HPP
#define BOOST_MPL2_CORE_IF_HPP

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        template<typename cond, typename then, typename else_, typename... _>
        struct if_;

        template<typename cond, typename then, typename elsecond, typename elsethen, typename else_, typename... _>
        struct if_<cond, then, elsecond, elsethen, else_, _...> :
                if_<cond, then, if_<elsecond, elsethen, else_, _...>>
        {};

        template<typename cond, typename then, typename else_>
        struct if_<cond, then, else_> :
                std::conditional<!!cond::value, then, else_>::type
        {};
    }
}

#endif
