/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_EVAL_HPP
#define METAL_FUNCTIONAL_EVAL_HPP

namespace metal
{
    namespace detail
    {
        template<template<typename...> class expr, typename... args>
        struct eval
        {
        private:
            struct empty {};

            template<template<typename...> class>
            static empty impl(...);
            template<template<typename...> class e, typename = typename e<args...>::type>
            static e<args...> impl(int);

        public:
            using type = decltype(impl<expr>(0));
        };
    }

    template<template<typename...> class expr, typename... args>
    struct eval :
            detail::eval<expr, args...>::type
    {};

    template<template<typename...> class expr, typename... args>
    using eval_t = typename eval<expr, args...>::type;
}

#endif
