// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_TRAITS_IS_FUNCTION_HPP
#define BOOST_MPL2_METAFUNCTIONAL_TRAITS_IS_FUNCTION_HPP

#include <boost/mpl2/core/traits_factory.hpp>
#include <boost/mpl2/core/logical/and.hpp>
#include <boost/mpl2/core/logical/not.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_call, call);
            BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(has_template_call, call);
        }

        template<typename func>
        struct is_function :
                and_<
                    not_<detail::has_call<func>>,
                    detail::has_template_call<func>
                >
        {};
    }
}

#endif
