// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_TRAITS_HPP
#define BOOST_MPL2_LAMBDA_TRAITS_HPP

#include <boost/mpl2/lambda/logical/and.hpp>
#include <boost/mpl2/lambda/logical/or.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/function.hpp>
#include <boost/mpl2/lambda/nullary.hpp>
#include <boost/mpl2/lambda/bind.hpp>
#include <boost/mpl2/lambda/call.hpp>
#include <boost/mpl2/lambda/detail/nested_type_trait.hpp>
#include <boost/mpl2/lambda/detail/nested_template_trait.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            BOOST_MPL2_DEFINE_NESTED_TYPE_TRAIT(has_type, type);

            template<typename x, typename... args>
            struct is_call_valid
            {
            private:
                template<template<typename...> class y>
                static boost::mpl2::true_ check(int(*)[sizeof(y<args...>)]);
                template<template<typename...> class>
                static boost::mpl2::false_ check(...);

            public:
                using type = decltype(check<x::template call>(0));
                using value_type = typename type::value_type;
                static constexpr value_type value = type::value;
                constexpr operator value_type() const noexcept {return value;}
                constexpr value_type operator()() const noexcept {return value;}
            };
        }

        BOOST_MPL2_DEFINE_NESTED_TEMPLATE_TRAIT(is_function, call);

        template<typename x, typename... args>
        using is_callable = and_<
            is_function<x>,
            detail::is_call_valid<x, args...>,
            detail::has_type<call<x, args...> >
        >;
    }
}

#endif
