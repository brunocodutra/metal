/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_METAL_FUNCTIONAL_TRAITS_IS_QUOTABLE_HPP
#define BOOST_METAL_FUNCTIONAL_TRAITS_IS_QUOTABLE_HPP

#include <boost/metal/functional/quote.hpp>
#include <boost/metal/functional/traits/detail/has_type.hpp>

namespace boost
{
    namespace metal
    {
        template<template<typename...> class expr, typename... args>
        struct is_quotable :
                detail::has_type<quote<expr, args...>>
        {};

        template<template<typename...> class expr, typename... args>
        using is_quotable_t = typename is_quotable<expr, args...>::type;
    }
}

#endif
