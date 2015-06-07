// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_EVALUATOR_HPP
#define BOOST_MPL2_METAFUNCTIONAL_EVALUATOR_HPP

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr>
        struct evaluator
        {
        private:
            template<typename> struct type_wrapper;
            struct empty {};

            template<template<typename...> class, typename...>
            static empty impl(...);
            template<template<typename...> class e, typename... args>
            static e<args...> impl(type_wrapper<typename e<args...>::type>*);

        public:
            using type = evaluator;

            template<typename... args>
            struct call :
                    decltype(impl<expr, args...>(0))
            {};
        };
    }
}

#endif
