// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_TRAIT_HPP
#define BOOST_MPL2_CORE_TRAIT_HPP

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
