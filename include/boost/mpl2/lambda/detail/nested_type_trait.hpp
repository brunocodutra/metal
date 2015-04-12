// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_NESTED_TYPE_TRAIT_HPP
#define BOOST_MPL2_LAMBDA_NESTED_TYPE_TRAIT_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>

#define BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(TRAIT, NESTED) \
    template<typename x> \
    struct TRAIT \
    { \
    private: \
        template<typename> \
        struct type_wrapper; \
        template<typename y> \
        static boost::mpl2::true_ check(type_wrapper<typename y::NESTED>*); \
        template<typename> \
        static boost::mpl2::false_ check(...); \
    public: \
        using type = decltype(check<x>(0)); \
        using value_type = typename type::value_type; \
        static constexpr value_type value = type::value; \
        constexpr operator value_type() const noexcept {return value;} \
        constexpr value_type operator()() const noexcept {return value;} \
    } \
/**/

#endif
