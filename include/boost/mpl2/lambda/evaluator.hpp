// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_EVALUATOR_HPP
#define BOOST_MPL2_LAMBDA_EVALUATOR_HPP

#include <boost/mpl2/lambda/integral/boolean.hpp>
#include <boost/mpl2/lambda/if.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr>
        struct evaluator
        {
        private:
            template<typename>
            struct wrapper;

            template<typename... args>
            static true_ try_eval_impl(wrapper<typename expr<args...>::type>*);
            template<typename...>
            static false_ try_eval_impl(...);

            template<typename... args>
            struct try_eval :
                    decltype(try_eval_impl<args...>(0))
            {};

            template<typename... args>
            struct do_eval
            {
                using type = typename expr<args...>::type;
            };

            struct undefined_evaluation
            {};

        public:
            template<typename... args>
            using call = if_<
                try_eval<args...>,
                do_eval<args...>,
                undefined_evaluation
            >;
        };
    }
}

#endif
