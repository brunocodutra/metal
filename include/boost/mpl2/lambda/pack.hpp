// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_PACK_HPP
#define BOOST_MPL2_LAMBDA_PACK_HPP

#include <boost/mpl2/lambda/integral/size_t.hpp>
#include <boost/mpl2/lambda/arithmetic/inc.hpp>
#include <boost/mpl2/lambda/identity.hpp>
#include <boost/mpl2/lambda/if.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename...>
        struct sizeof_;

        template<typename... args>
        struct pack;

        template<typename h, typename... t>
        struct pack<h, t...> :
                pack<h, pack<t...> >
        {};

        template<typename... largs, typename... rargs>
        struct pack<pack<largs...>, pack<rargs...> > :
                pack<largs..., rargs...>
        {};

        template<typename h, typename... t>
        struct pack<h, pack<t...> > :
                identity<pack<h, pack<t...> > >
        {
            using head = identity<h>;
            using tail = pack<t...>;
            using size = inc<sizeof_<tail> >;
        };

        template<typename... args>
        struct pack<pack<args...> > :
                pack<args...>
        {};

        template<typename h>
        struct pack<h> :
                pack<h, pack<> >
        {};

        template<>
        struct pack<> :
                identity<pack<> >
        {
            struct head {};
            using tail = pack<>;
            using size = size_t_<0>;
        };

        template<typename... args>
        using head = typename pack<args...>::head;

        template<typename... args>
        using tail = typename pack<args...>::tail;

        template<typename... args>
        struct sizeof_ :
                sizeof_<pack<args...> >
        {};

        template<typename... args>
        struct sizeof_<pack<args...> > :
                pack<args...>::size
        {};

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
            {};

            struct empty{};
        }

        template<template<typename...> class tmpl, typename pack, typename... unpacked>
        struct unpack;

        template<template<typename...> class tmpl, typename... args, typename... unpacked>
        struct unpack<tmpl, pack<args...>, unpacked...> :
                if_<
                    sizeof_<pack<args...> >,
                    unpack<
                        tmpl,
                        tail<pack<args...> >,
                        unpacked...,
                        head<pack<args...> >
                    >,
                    detail::is_instantiable<tmpl, typename unpacked::type...>,
                    detail::instantiate<tmpl, typename unpacked::type...>,
                    detail::empty
                >
        {};
    }
}

#endif
