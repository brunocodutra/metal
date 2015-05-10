// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_TRAITS_HPP
#define BOOST_MPL2_LAMBDA_TRAITS_HPP

#include <boost/mpl2/lambda/logical/and.hpp>
#include <boost/mpl2/lambda/logical/not.hpp>
#include <boost/mpl2/lambda/detail/traits_factory.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            BOOST_MPL2_DETAIL_DEFINE_NESTED_TYPE_TRAIT(has_call, call);
            BOOST_MPL2_DETAIL_DEFINE_NESTED_TEMPLATE_TRAIT(has_template_call, call);
        }

        BOOST_MPL2_DETAIL_DEFINE_NESTED_TYPE_TRAIT(is_evaluable, type);

        template<typename func>
        using is_function = and_<
            not_<detail::has_call<func> >,
            detail::has_template_call<func>
        >;
    }
}

#endif
