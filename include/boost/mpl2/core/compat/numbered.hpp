/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL2_CORE_COMPAT_NUMBERED_HPP_
#define _BOOST_MPL2_CORE_COMPAT_NUMBERED_HPP_

#include <boost/mpl2/core/if_c.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/compat/detail/na.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/elem.hpp>

// FOR EACH
#define __BOOST_MPL2_FOR_NAME(Z, N, DATA) \
    BOOST_PP_SEQ_ELEM(1, DATA)( \
        BOOST_PP_SEQ_ELEM(2, DATA), \
        BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(0, DATA), N) \
    )

#define __BOOST_MPL2_FOR_EACH_NAME(N, PREFIX, MACRO, DATA) \
    BOOST_PP_ENUM(N, __BOOST_MPL2_FOR_NAME, (PREFIX)(MACRO)(DATA))

// APPLY TO EACH ARG
#define __BOOST_MPL2_APPLY_TO_ARG(TMPL, ARG) \
    typename boost::mpl2::if_c< \
        boost::is_same<ARG, boost::mpl2::detail::na>::type::value, \
        boost::mpl2::identity<ARG>, \
        TMPL<ARG> \
    >::type

#define BOOST_MPL2_APPLY_TO_EACH_ARG(N, PREFIX, TMPL) \
    __BOOST_MPL2_FOR_EACH_NAME(N, PREFIX, __BOOST_MPL2_APPLY_TO_ARG, TMPL)

#define BOOST_MPL2_APPLY_TO_EACH_LEADING_ARG(N, PREFIX, TMPL) \
    BOOST_MPL2_APPLY_TO_EACH_ARG(N, PREFIX, TMPL) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_APPLY_TO_EACH_TRAILING_ARG(N, PREFIX, TMPL) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_APPLY_TO_EACH_ARG(N, PREFIX, TMPL)

// WRAP EACH ARG
#define __BOOST_MPL2_WRAP_ARG(TMPL, ARG) \
    typename boost::mpl2::if_c< \
        boost::is_same<ARG, boost::mpl2::detail::na>::type::value, \
        boost::mpl2::identity<ARG>, \
        boost::mpl2::identity<TMPL<ARG> > \
    >::type

#define BOOST_MPL2_WRAP_EACH_ARG(N, PREFIX, TMPL) \
    __BOOST_MPL2_FOR_EACH_NAME(N, PREFIX, __BOOST_MPL2_WRAP_ARG, TMPL)

#define BOOST_MPL2_WRAP_EACH_LEADING_ARG(N, PREFIX, TMPL) \
    BOOST_MPL2_WRAP_EACH_ARG(N, PREFIX, TMPL) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_WRAP_EACH_TRAILING_ARG(N, PREFIX, TMPL) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_WRAP_EACH_ARG(N, PREFIX, TMPL)

// ARGS
#define BOOST_MPL2_ARGS(N, PREFIX) \
    BOOST_PP_ENUM_PARAMS(N, PREFIX)

#define BOOST_MPL2_LEADING_ARGS(N, PREFIX) \
    BOOST_MPL2_ARGS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_ARGS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_ARGS(N, PREFIX)

// WRAP EACH PARAM
#define __BOOST_MPL2_WRAP_PARAM(TMPL, PARAM) \
    TMPL<PARAM>

#define BOOST_MPL2_WRAP_EACH_PARAM(N, PREFIX, TMPL) \
    __BOOST_MPL2_FOR_EACH_NAME(N, PREFIX, __BOOST_MPL2_WRAP_PARAM, TMPL)

#define BOOST_MPL2_WRAP_EACH_LEADING_PARAM(N, PREFIX, TMPL) \
    BOOST_MPL2_WRAP_EACH_PARAM(N, PREFIX, TMPL) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_WRAP_EACH_TRAILING_PARAM(N, PREFIX, TMPL) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_WRAP_EACH_PARAM(N, PREFIX, TMPL)

// PARAMS
#define BOOST_MPL2_PARAMS(N, PREFIX) \
    BOOST_PP_ENUM_PARAMS(N, typename PREFIX)

#define BOOST_MPL2_LEADING_PARAMS(N, PREFIX) \
    BOOST_MPL2_PARAMS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_PARAMS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_PARAMS(N, PREFIX)

// OPTIONAL PARAMS
#define BOOST_MPL2_OPTIONAL_PARAMS(N, PREFIX) \
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(N, typename PREFIX, boost::mpl2::detail::na)

#define BOOST_MPL2_LEADING_OPTIONAL_PARAMS(N, PREFIX) \
    BOOST_MPL2_OPTIONAL_PARAMS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_OPTIONAL_PARAMS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_OPTIONAL_PARAMS(N, PREFIX)

#endif
