// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_TRAITS_IS_EVALUABLE_HPP
#define BOOST_MPL2_METAFUNCTIONAL_TRAITS_IS_EVALUABLE_HPP

#include <boost/mpl2/core/traits_factory.hpp>
#include <boost/mpl2/metafunctional/eval.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_type, type);
        }

        template<template<typename...> class expr, typename... args>
        struct is_evaluable :
                detail::has_type<eval<expr, args...> >
        {};
    }
}

#endif
