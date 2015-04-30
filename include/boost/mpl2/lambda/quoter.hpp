// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_QUOTER_HPP
#define BOOST_MPL2_LAMBDA_QUOTER_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/if.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr>
        struct quoter
        {
        private:
            template<typename>
            struct voider
            {
                using type = void;
            };

            template<typename... args>
            static true_ try_quote_impl(typename voider<expr<args...> >::type*);
            template<typename...>
            static false_ try_quote_impl(...);

            template<typename... args>
            struct try_quote :
                    decltype(try_quote_impl<args...>(0))
            {};

            template<typename... args>
            struct quote
            {
                using type = expr<args...>;
            };

            struct undefined_quoting
            {};

        public:
            template<typename... args>
            using call = if_<
                try_quote<args...>,
                quote<args...>,
                undefined_quoting
            >;
        };
    }
}

#endif
