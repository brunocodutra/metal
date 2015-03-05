/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL2_CONFIG_LIMITS_ARITY_HPP_
#define _BOOST_MPL2_CONFIG_LIMITS_ARITY_HPP_

#if !defined(BOOST_MPL2_LIMIT_METAFUNCTION_ARITY)
    #include <boost/mpl2/config/switches/variadic.hpp>

    #if defined(BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES)
        #define BOOST_MPL2_LIMIT_METAFUNCTION_ARITY 20U
    #else
        #include <cstdint>
        #if !defined(SIZE_MAX)
            #define SIZE_MAX UINT_MAX
        #endif
        #define BOOST_MPL2_LIMIT_METAFUNCTION_ARITY SIZE_MAX
    #endif
#endif

#endif
