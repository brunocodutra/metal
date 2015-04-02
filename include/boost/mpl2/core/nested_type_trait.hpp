// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_NESTED_TYPE_TRAIT_HPP
#define BOOST_MPL2_CORE_NESTED_TYPE_TRAIT_HPP

#include <boost/mpl2/integrals/boolean.hpp>
#include <boost/mpl2/core/ref.hpp>

#define BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(TRAIT, NESTED) \
    struct TRAIT##_impl \
    { \
        template<typename x> \
        static boost::mpl2::true_ check(boost::mpl2::ref<typename x::NESTED>*); \
        template<typename x> \
        static boost::mpl2::false_ check(...); \
        template<typename x> \
        using apply = decltype(check<x>(0)); \
    }; \
    template<typename x> \
    using TRAIT = TRAIT##_impl::template apply<x> \
/**/

#endif
