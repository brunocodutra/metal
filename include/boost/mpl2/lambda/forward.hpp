// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_FORWARD_HPP
#define BOOST_MPL2_LAMBDA_FORWARD_HPP

#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/if.hpp>

namespace boost
{
    namespace mpl2
    {
        namespace detail
        {
            template<template<typename...> class x, typename... args>
            struct is_instantiable
            {
            private:
                template<template<typename...> class y>
                static boost::mpl2::true_ check(int(*)[sizeof(y<args...>)]);
                template<template<typename...> class>
                static boost::mpl2::false_ check(...);

            public:
                using type = decltype(check<x>(0));
                using value_type = typename type::value_type;
                static constexpr value_type value = type::value;
                constexpr operator value_type() const noexcept {return value;}
                constexpr value_type operator()() const noexcept {return value;}
            };

            template<template<typename...> class tmpl, typename... args>
            struct instantiate :
                    tmpl<args...>
            {
            private:
                //prevents instantiate from being detected as a function
                //in case a template<...> call is inherited
                using call = void;
            };

            struct empty{};

            template<template<typename...> class tmpl, typename pack, typename... unpacked>
            struct forward;

            template<template<typename...> class tmpl, typename... args, typename... unpacked>
            struct forward<tmpl, pack<args...>, unpacked...> :
                    if_<
                        sizeof_<pack<args...> >,
                        forward<
                            tmpl,
                            tail<pack<args...> >,
                            unpacked...,
                            head<pack<args...> >
                        >,
                        is_instantiable<tmpl, typename unpacked::type...>,
                        instantiate<tmpl, typename unpacked::type...>,
                        empty
                    >
            {};
        }

        template<template<typename...> class tmpl, typename... args>
        using forward = detail::forward<tmpl, pack<args...> >;
    }
}

#endif
