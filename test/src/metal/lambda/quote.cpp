// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/quote.hpp>
#include <metal/lambda/apply.hpp>

#include "test.hpp"

#define _boilerplate(_, N) \
    _assert((metal::quote_t<_val(N)>::type), (_val(N))); \
    _assert((metal::quote_t<_num(N)>::type), (_num(N))); \
    _assert((metal::quote_t<_pair(N)>::type), (_pair(N))); \
    _assert((metal::quote_t<_list(N)>::type), (_list(N))); \
    _assert((metal::quote_t<_map(N)>::type), (_map(N))); \
    _assert((metal::quote_t<_arg(N)>::type), (_arg(N))); \
    _assert((metal::quote_t<_lbd(N)>::type), (_lbd(N))); \
    _assert((metal::apply_t<metal::quote_t<_val(N)>>), (_val(N))); \
    _assert((metal::apply_t<metal::quote_t<_num(N)>>), (_num(N))); \
    _assert((metal::apply_t<metal::quote_t<_pair(N)>>), (_pair(N))); \
    _assert((metal::apply_t<metal::quote_t<_list(N)>>), (_list(N))); \
    _assert((metal::apply_t<metal::quote_t<_map(N)>>), (_map(N))); \
    _assert((metal::apply_t<metal::quote_t<_arg(N)>>), (_arg(N))); \
    _assert((metal::apply_t<metal::quote_t<_lbd(N)>>), (_lbd(N))); \
/**/

_gen(_boilerplate)
