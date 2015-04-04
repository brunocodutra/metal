// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_NESTED_TEMPLATE_TRAIT_HPP
#define BOOST_MPL2_CORE_NESTED_TEMPLATE_TRAIT_HPP

#include <boost/mpl2/integrals/boolean.hpp>

#define BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(TRAIT, NESTED) \
    template<typename x> \
    struct TRAIT \
    { \
        template<template<typename...> class> \
        struct template_wrapper; \
        template<typename y> \
        static boost::mpl2::true_ check(template_wrapper<y::template NESTED>*); \
        template<typename> \
        static boost::mpl2::false_ check(...); \
        using type = decltype(check<x>(0)); \
        using value_type = typename type::value_type; \
        static constexpr value_type value = type::value; \
        constexpr operator value_type() const noexcept {return value;} \
        constexpr value_type operator()() const noexcept {return value;} \
    } \
/**/

#endif
