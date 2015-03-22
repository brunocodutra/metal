// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CONFIG_LIMITS_ARITY_HPP
#define BOOST_MPL2_CONFIG_LIMITS_ARITY_HPP

#if !defined(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY)
    #include <boost/mpl2/config/options/variadic_templates.hpp>

    #if defined(BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES)
        #define BOOST_MPL2_LIMIT_METAFUNCTION_ARITY 20
    #else
        #include <boost/preprocessor/config/limits.hpp>
        #define BOOST_MPL2_LIMIT_METAFUNCTION_ARITY BOOST_PP_LIMIT_MAG
    #endif
#endif

#endif
