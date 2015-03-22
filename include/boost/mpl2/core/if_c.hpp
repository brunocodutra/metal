// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_IF_C_HPP
#define BOOST_MPL2_CORE_IF_C_HPP

namespace boost
{
    namespace mpl2
    {
        template<bool cond, typename yes, typename no>
        struct if_c :
                yes
        {};

        template<typename yes, typename no>
        struct if_c<false, yes, no> :
                no
        {};
    }
}

#endif
