/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL_CONFIG_SWITCHES_TYPEOF_HPP_
#define _BOOST_MPL_CONFIG_SWITCHES_TYPEOF_HPP_

#include <boost/typeof/typeof.hpp>

#if !defined(BOOST_MPL_CFG_NO_TYPEOF) && \
        (!defined(BOOST_TYPEOF) || !defined(BOOST_TYPEOF_TPL))
    #define BOOST_MPL_CFG_NO_TYPEOF
#endif

#endif
