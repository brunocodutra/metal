/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL_DETAIL_PREPROCESSOR_TYPEOF_HPP_
#define _BOOST_MPL_DETAIL_PREPROCESSOR_TYPEOF_HPP_

#include <boost/mpl2/config/switches/typeof.hpp>

#if !defined(BOOST_MPL_CFG_NO_TYPEOF)
    #include <boost/typeof/typeof.hpp>

    #define BOOST_MPL_TYPEOF(EXPR) BOOST_TYPEOF(EXPR)
    #define BOOST_MPL_TYPEOF_TPL(EXPR) BOOST_TYPEOF_TPL(EXPR)
#endif

#endif
