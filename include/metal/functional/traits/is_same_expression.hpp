// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_FUNCTIONAL_TRAITS_IS_SAME_EXPRESSION_HPP
#define METAL_FUNCTIONAL_TRAITS_IS_SAME_EXPRESSION_HPP

#include <type_traits>

namespace metal
{
    template<template<typename...> class, template<typename...> class>
    struct is_same_expression :
            std::false_type
    {};

    template<template<typename...> class expr>
    struct is_same_expression<expr, expr> :
            std::true_type
    {};

    /// \ingroup functional_traits
    /// \brief Eager adaptor for is_same_expression.
    template<template<typename...> class x, template<typename...> class y>
    using is_same_expression_t = typename is_same_expression<x, y>::type;
}

#endif
