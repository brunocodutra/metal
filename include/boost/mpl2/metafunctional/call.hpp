// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_CALL_HPP
#define BOOST_MPL2_METAFUNCTIONAL_CALL_HPP

namespace boost
{
    namespace mpl2
    {
        template<typename function, typename... args>
        using call = typename function::template call<args...>;
    }
}

#endif
