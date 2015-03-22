// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CONFIG_OPTIONS_VARIADIC_HPP
#define BOOST_MPL2_CONFIG_OPTIONS_VARIADIC_HPP

#include <boost/config.hpp>

#if !defined(BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES) && \
        defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    #define BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES
#endif

#endif
