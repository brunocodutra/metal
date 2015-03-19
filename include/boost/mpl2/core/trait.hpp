/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL2_CORE_TRAIT_HPP_
#define _BOOST_MPL2_CORE_TRAIT_HPP_

#include <boost/mpl2/core/integral/boolean.hpp>

#include <boost/preprocessor/cat.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<typename>
            struct type_wrapper
            {};
        }
    }
}

#define BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(trait, nested) \
    struct BOOST_PP_CAT(trait, _impl) \
    { \
        template<typename U> \
        static char const (&check( \
            boost::mpl2::detail::type_wrapper<U>, \
            boost::mpl2::detail::type_wrapper<typename U::nested>* = 0 \
        ))[1]; \
        static char const (&check(...))[2]; \
    }; \
    template<typename T> \
    struct trait : \
            boost::mpl2::bool_< \
                sizeof(BOOST_PP_CAT(trait, _impl)::check( \
                    boost::mpl2::detail::type_wrapper<T>() \
                )) == sizeof(char const(&)[1]) \
            > \
         \
    {};

#endif
