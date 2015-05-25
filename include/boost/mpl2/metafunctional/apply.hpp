// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_APPLY_HPP
#define BOOST_MPL2_METAFUNCTIONAL_APPLY_HPP

#include <boost/mpl2/metafunctional/lambda.hpp>
#include <boost/mpl2/metafunctional/call.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename...>
        struct apply
        {};

        template<typename function, typename... args>
        struct apply<function, args...> :
                call<lambda<function>, args...>
        {};
    }
}

#endif
