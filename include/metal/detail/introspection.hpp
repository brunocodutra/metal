// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_DETAIL_INTROSPECTION_HPP
#define METAL_DETAIL_INTROSPECTION_HPP

#include <type_traits>

#define METAL_DEFINE_NESTED_TYPE_TRAIT(TRAIT, NESTED) \
    template<typename TRAIT##_candidate> \
    struct TRAIT##_impl \
    { \
    private: \
        template<typename> struct type_wrapper; \
        template<typename y, typename = type_wrapper<typename y::NESTED>> \
        static std::true_type check(int); \
        template<typename> \
        static std::false_type check(...); \
    public: \
        using type = decltype(check<TRAIT##_candidate>(0)); \
    }; \
    template<typename TRAIT##_candidate> \
    struct TRAIT : \
            TRAIT##_impl<TRAIT##_candidate>::type \
    {}; \
    template<typename TRAIT##_candidate> \
    using TRAIT##_t = typename TRAIT<TRAIT##_candidate>::type
/**/

#define METAL_DEFINE_NESTED_TEMPLATE_TRAIT(TRAIT, NESTED) \
    template<typename TRAIT##_candidate> \
    struct TRAIT##_impl \
    { \
    private: \
        template<template<typename...> class> struct template_wrapper; \
        template<typename y, typename = template_wrapper<y::template NESTED>> \
        static std::true_type check(int); \
        template<typename> \
        static std::false_type check(...); \
    public: \
        using type = decltype(check<TRAIT##_candidate>(0)); \
    }; \
    template<typename TRAIT##_candidate> \
    struct TRAIT : \
            TRAIT##_impl<TRAIT##_candidate>::type \
    {}; \
    template<typename TRAIT##_candidate> \
    using TRAIT##_t = typename TRAIT<TRAIT##_candidate>::type
/**/

#endif
