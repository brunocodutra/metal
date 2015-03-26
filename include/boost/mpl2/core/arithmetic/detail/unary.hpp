// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_ARITHMETIC_DETAIL_UNARY_HPP
#define BOOST_MPL2_CORE_ARITHMETIC_DETAIL_UNARY_HPP

#include <boost/mpl2/core/tag.hpp>
#include <boost/mpl2/core/integral.hpp>
#include <boost/mpl2/core/logical/not.hpp>
#include <boost/mpl2/core/compat/alias.hpp>

#include <boost/preprocessor/cat.hpp>

#define BOOST_MPL2_DETAIL_DEFINE_UNARY_ARITHMETIC_OPERATION(NAME, OP) \
    template<typename tag> \
    struct BOOST_PP_CAT(NAME, _impl); \
    template<typename type> \
    struct BOOST_PP_CAT(NAME, _impl)<integral_tag<type> > \
    { \
        template<typename n> \
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS( \
            apply, \
            (integral< \
                typename n::value_type, \
                static_cast<typename n::value_type>(OP n::value) \
            >) \
        ); \
    }; \
    template<> \
    struct BOOST_PP_CAT(NAME, _impl)<integral_tag<bool> > \
    { \
        template<typename n> \
        BOOST_MPL2_DECLARE_TEMPLATE_ALIAS(apply, (not_<n>)); \
    }; \
    template<typename n> \
    struct NAME : \
            BOOST_PP_CAT(NAME, _impl)<typename tag<n>::type>::template apply<n> \
    {} \
/**/

#endif
