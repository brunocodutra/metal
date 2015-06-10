/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_TRAITS_IS_EVALUABLE_HPP
#define BOOST_METAL_FUNCTIONAL_TRAITS_IS_EVALUABLE_HPP

#include <boost/metal/functional/eval.hpp>
#include <boost/metal/functional/traits/detail/has_type.hpp>

namespace boost
{
    namespace metal
    {
        template<template<typename...> class expr, typename... args>
        struct is_evaluable :
                detail::has_type<eval<expr, args...>>
        {};

        template<template<typename...> class expr, typename... args>
        using is_evaluable_t = typename is_evaluable<expr, args...>::type;
    }
}

#endif
