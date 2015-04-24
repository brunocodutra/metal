// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_TRAITS_HPP
#define BOOST_MPL2_LAMBDA_TRAITS_HPP

#include <boost/mpl2/lambda/logical/and.hpp>
#include <boost/mpl2/lambda/logical/or.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/nullary.hpp>
#include <boost/mpl2/lambda/bind.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/detail/nested_type_trait.hpp>
#include <boost/mpl2/lambda/detail/nested_template_trait.hpp>

namespace boost
{
    namespace mpl2
    {
        BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(is_evaluable, type);
        BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(is_function, call);

        template<typename x, typename... args>
        using is_callable = and_<
            is_function<x>,
            is_evaluable<call<x, args...> >
        >;
    }
}

#endif
