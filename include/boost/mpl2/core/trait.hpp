/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL2_CORE_TRAIT_HPP_
#define _BOOST_MPL2_CORE_TRAIT_HPP_

#include <boost/mpl2/core/integral/boolean.hpp>
#include <boost/mpl2/core/ref.hpp>

#include <boost/preprocessor/cat.hpp>

#define BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(trait, nested) \
    struct BOOST_PP_CAT(trait, _impl) \
    { \
        template<typename T> \
        static char (&check( \
            boost::mpl2::ref<typename T::nested>* \
        ))[1]; \
        template<typename> \
        static char (&check(...))[2]; \
        template<typename T> \
        struct apply : \
                boost::mpl2::bool_< \
                    sizeof(check<T>(0)) == sizeof(char(&)[1]) \
                > \
        {}; \
    }; \
    template<typename T> \
    struct trait : \
            BOOST_PP_CAT(trait, _impl)::template apply<T> \
    {};

#endif
