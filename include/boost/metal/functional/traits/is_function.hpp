// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_TRAITS_IS_FUNCTION_HPP
#define BOOST_METAL_FUNCTIONAL_TRAITS_IS_FUNCTION_HPP

#include <boost/metal/core/introspection.hpp>
#include <boost/metal/algebra/logical/and.hpp>
#include <boost/metal/algebra/logical/not.hpp>

namespace boost
{
    namespace metal
    {
        namespace detail
        {
            BOOST_METAL_DEFINE_NESTED_TYPE_TRAIT(has_call, call);
            BOOST_METAL_DEFINE_NESTED_TEMPLATE_TRAIT(has_template_call, call);
        }

        template<typename func>
        struct is_function :
                and_<
                    not_<detail::has_call<func>>,
                    detail::has_template_call<func>
                >
        {};

        template<typename func>
        using is_function_t = typename is_function<func>::type;
    }
}

#endif
