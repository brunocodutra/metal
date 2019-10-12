#ifndef METAL_DETAIL_SFINAE_HPP
#define METAL_DETAIL_SFINAE_HPP

#include "../config.hpp"
#include "../detail/declptr.hpp"
#include "../value/eval.hpp"
#include "../value/value.hpp"

#include <type_traits>

namespace metal {
    /// \cond
    namespace detail {
        template<
            template<template<class...> class...> class,
            template<class...> class...>
        struct forwarder;

        template<
            template<template<class...> class...> class tmpl,
            template<class...> class... exprs,
            eval<std::enable_if<is_value<tmpl<exprs...>>::value>>* = nullptr>
        value<tmpl<exprs...>> sfinae(forwarder<tmpl, exprs...>*);

        template<template<class...> class expr, class... vals>
        struct caller;

        template<
            template<class...> class expr, class... vals,
            eval<std::enable_if<is_value<expr<vals...>>::value>>* = nullptr>
        value<expr<vals...>> sfinae(caller<expr, vals...>*);

        value<> sfinae(...);

        template<
            template<template<class...> class...> class tmpl,
            template<class...> class... exprs>
        struct forwarder
            : decltype(sfinae(declptr<forwarder<tmpl, exprs...>>())) {};

        template<template<class...> class expr, class... vals>
        struct caller : decltype(sfinae(declptr<caller<expr, vals...>>())) {};

#if defined(METAL_WORKAROUND)
        template<
            template<template<class...> class...> class tmpl,
            template<class...> class... exprs>
        using forward = typename forwarder<tmpl, exprs...>::type;

        template<template<class...> class expr, class... vals>
        using call = typename caller<expr, vals...>::type;
#else
        template<
            template<template<class...> class...> class tmpl,
            template<class...> class... exprs>
        using forward = tmpl<exprs...>;

        template<template<class...> class expr, class... vals>
        using call = expr<vals...>;
#endif
    }
    /// \endcond
}

#endif
