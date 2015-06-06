// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_PROTECT_HPP
#define BOOST_MPL2_METAFUNCTIONAL_PROTECT_HPP

#include <boost/mpl2/metafunctional/traits/is_function.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename function, typename = typename is_function<function>::type>
            struct forward :
                    function
            {};

            template<typename not_a_function>
            struct forward<not_a_function, std::false_type>
            {
                template<typename...>
                struct call
                {};
            };
        }

        template<typename function>
        struct protect :
                detail::forward<function>
        {
            using type = protect;
        };
    }
}

#endif
