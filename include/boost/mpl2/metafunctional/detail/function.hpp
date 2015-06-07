// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_DETAIL_FUNCTION_HPP
#define BOOST_MPL2_METAFUNCTIONAL_DETAIL_FUNCTION_HPP

#include <boost/mpl2/metafunctional/traits/is_function.hpp>

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename func, typename = typename is_function<func>::type>
            struct function :
                    func
            {};

            template<typename not_a_function>
            struct function<not_a_function, std::false_type>
            {
                template<typename...>
                struct call
                {};
            };
        }
    }
}

#endif
