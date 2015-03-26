// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_COMPAT_TEMPLATE_ALIAS_HPP
#define BOOST_MPL2_CORE_COMPAT_TEMPLATE_ALIAS_HPP

#include <boost/config.hpp>
#include <boost/preprocessor/config/config.hpp>

#if defined(BOOST_NO_CXX11_TEMPLATE_ALIASES) || !defined(BOOST_PP_VARIADICS)
    #include <boost/mpl2/core/detail/type.hpp>
    #define BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(ALIAS, BASE) \
        struct ALIAS : BOOST_MPL2_DETAIL_TYPE(BASE) {}  \
    /**/

#else
    #include <boost/preprocessor/tuple/enum.hpp>
    #define BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(ALIAS, BASE) \
        using ALIAS = BOOST_PP_TUPLE_ENUM(BASE) \
    /**/

#endif

#endif
