// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_METAFUNCTIONAL_EVAL_HPP
#define BOOST_MPL2_METAFUNCTIONAL_EVAL_HPP

#include <boost/mpl2/metafunctional/evaluator.hpp>

namespace boost
{
    namespace mpl2
    {
        template<template<typename...> class expr, typename... args>
        struct eval :
                evaluator<expr>::template call<args...>
        {};

        template<template<typename...> class expr, typename... args>
        using eval_t = typename eval<expr, args...>::type;
    }
}

#endif
