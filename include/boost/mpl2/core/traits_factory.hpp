// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_TRAITS_FACTORY_HPP
#define BOOST_MPL2_CORE_TRAITS_FACTORY_HPP

#include <boost/mpl2/core/integral.hpp>

#define BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(TRAIT, NESTED) \
    template<typename x> \
    struct TRAIT##_impl \
    { \
    private: \
        template<typename> struct type_wrapper; \
        template<typename y> \
        static boost::mpl2::true_ check(type_wrapper<typename y::NESTED>*); \
        template<typename> \
        static boost::mpl2::false_ check(...); \
    public: \
        using type = decltype(check<x>(0)); \
    }; \
    template<typename x> \
    struct TRAIT : \
            TRAIT##_impl<x>::type \
    {} \
/**/

#define BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(TRAIT, NESTED) \
    template<typename x> \
    struct TRAIT##_impl \
    { \
    private: \
        template<template<typename...> class> struct template_wrapper; \
        template<typename y> \
        static boost::mpl2::true_ check(template_wrapper<y::template NESTED>*); \
        template<typename> \
        static boost::mpl2::false_ check(...); \
    public: \
        using type = decltype(check<x>(0)); \
    }; \
    template<typename x> \
    struct TRAIT : \
            TRAIT##_impl<x>::type \
    {} \
/**/

#endif
