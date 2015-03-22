/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef BOOST_MPL2_CONFIG_OPTIONS_DECLTYPE_HPP
#define BOOST_MPL2_CONFIG_OPTIONS_DECLTYPE_HPP

#include <boost/config.hpp>

#if !defined(BOOST_MPL2_CFG_NO_DECLTYPE) && defined(BOOST_NO_DECLTYPE)
    #define BOOST_MPL2_CFG_NO_DECLTYPE
#endif

#endif
