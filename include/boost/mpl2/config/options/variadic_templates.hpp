/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL2_CONFIG_OPTIONS_VARIADIC_HPP_
#define _BOOST_MPL2_CONFIG_OPTIONS_VARIADIC_HPP_

#include <boost/config.hpp>

#if !defined(BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES) && \
        defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
    #define BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES
#endif

#endif
