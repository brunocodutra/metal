// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_COMPAT_STATIC_CONSTANT_HPP
#define BOOST_MPL2_CORE_COMPAT_STATIC_CONSTANT_HPP

#include <boost/config.hpp>

#if !defined(BOOST_NO_INCLASS_MEMBER_INITIALIZATION)
    #define BOOST_MPL2_DEFINE_STATIC_CONSTANT(TYPE, ASSIGNMENT) \
        BOOST_STATIC_CONSTEXPR TYPE ASSIGNMENT  \
    /**/
#else
    #define BOOST_MPL2_DEFINE_STATIC_CONSTANT(_, ASSIGNMENT) \
        enum {ASSIGNMENT} \
    /**/
#endif

#endif
