// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_COMPAT_NUMBERED_HPP
#define BOOST_MPL2_CORE_COMPAT_NUMBERED_HPP

#include <boost/mpl2/core/if.hpp>
#include <boost/mpl2/core/identity.hpp>
#include <boost/mpl2/core/compat/detail/na.hpp>

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/elem.hpp>

// FOR EACH
#define BOOST_MPL2_DETAIL_FOR_NAME(Z, N, DATA) \
    BOOST_PP_SEQ_ELEM(1, DATA)( \
        BOOST_PP_SEQ_ELEM(2, DATA), \
        BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(0, DATA), N) \
    )

#define BOOST_MPL2_DETAIL_FOR_EACH_NAME(N, PREFIX, MACRO, DATA) \
    BOOST_PP_ENUM(N, BOOST_MPL2_DETAIL_FOR_NAME, (PREFIX)(MACRO)(DATA))

// APPLY TO EACH ARG
#define BOOST_MPL2_DETAIL_APPLY_TO_ARG(TMPL, ARG) \
    typename boost::mpl2::if_< \
        boost::mpl2::detail::is_na<ARG>, \
        boost::mpl2::identity<ARG>, \
        TMPL<ARG> \
    >::type

#define BOOST_MPL2_APPLY_TO_EACH_ARG(N, PREFIX, TMPL) \
    BOOST_MPL2_DETAIL_FOR_EACH_NAME(N, PREFIX, BOOST_MPL2_DETAIL_APPLY_TO_ARG, TMPL)

#define BOOST_MPL2_APPLY_TO_EACH_LEADING_ARG(N, PREFIX, TMPL) \
    BOOST_MPL2_APPLY_TO_EACH_ARG(N, PREFIX, TMPL) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_APPLY_TO_EACH_TRAILING_ARG(N, PREFIX, TMPL) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_APPLY_TO_EACH_ARG(N, PREFIX, TMPL)

// WRAP EACH ARG
#define BOOST_MPL2_DETAIL_WRAP_ARG(TMPL, ARG) \
    typename boost::mpl2::if_< \
        boost::mpl2::detail::is_na<ARG>, \
        boost::mpl2::identity<ARG>, \
        boost::mpl2::identity<TMPL<ARG> > \
    >::type

#define BOOST_MPL2_WRAP_EACH_ARG(N, PREFIX, TMPL) \
    BOOST_MPL2_DETAIL_FOR_EACH_NAME(N, PREFIX, BOOST_MPL2_DETAIL_WRAP_ARG, TMPL)

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
#define BOOST_MPL2_DETAIL_WRAP_PARAM(TMPL, PARAM) \
    TMPL<PARAM>

#define BOOST_MPL2_WRAP_EACH_PARAM(N, PREFIX, TMPL) \
    BOOST_MPL2_DETAIL_FOR_EACH_NAME(N, PREFIX, BOOST_MPL2_DETAIL_WRAP_PARAM, TMPL)

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
