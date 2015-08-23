// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/bind.hpp>
#include <metal/lambda/apply.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>

#include "test.hpp"

_assert((metal::apply_t<metal::bind_t<lbd0, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr0<>::type));
_assert((metal::apply_t<metal::bind_t<lbd1, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr1<val3>::type));
_assert((metal::apply_t<metal::bind_t<lbd2, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr2<val3, val2>::type));
_assert((metal::apply_t<metal::bind_t<lbd3, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr3<val3, val2, val1>::type));
_assert((metal::apply_t<metal::bind_t<lbd4, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr<val3, val2, val1, val0>::type));

_assert((metal::apply_t<metal::bind_t<metal::quote_t<lbd0>, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (lbd0));
_assert((metal::apply_t<metal::bind_t<metal::quote_t<lbd1>, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (lbd1));
_assert((metal::apply_t<metal::bind_t<metal::quote_t<lbd2>, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (lbd2));
_assert((metal::apply_t<metal::bind_t<metal::quote_t<lbd3>, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (lbd3));
_assert((metal::apply_t<metal::bind_t<metal::quote_t<lbd4>, metal::_4, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (lbd4));

_assert((metal::apply_t<metal::bind_t<lbd0, metal::quote_t<metal::_4>, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr0<>::type));
_assert((metal::apply_t<metal::bind_t<lbd1, metal::quote_t<metal::_4>, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr1<metal::_4>::type));
_assert((metal::apply_t<metal::bind_t<lbd2, metal::quote_t<metal::_4>, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr2<metal::_4, val2>::type));
_assert((metal::apply_t<metal::bind_t<lbd3, metal::quote_t<metal::_4>, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr3<metal::_4, val2, val1>::type));
_assert((metal::apply_t<metal::bind_t<lbd4, metal::quote_t<metal::_4>, metal::_3, metal::_2, metal::_1>, val0, val1, val2, val3>), (expr<metal::_4, val2, val1, val0>::type));
