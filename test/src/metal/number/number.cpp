// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/number/number.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_number_t<_val(M)>), (_false)); \
    _assert((metal::is_number_t<_num(M)>), (_true)); \
    _assert((metal::is_number_t<_pair(M)>), (_false)); \
    _assert((metal::is_number_t<_list(M)>), (_false)); \
    _assert((metal::is_number_t<_map(M)>), (_false)); \
    _assert((metal::is_number_t<_arg(M)>), (_false)); \
    _assert((metal::is_number_t<_lbd(M)>), (_false)); \
    _assert((metal::is_number_t<_lambda(M)>), (_false)); \
    _assert((metal::is_number_t<metal::number<std::size_t, 0>>), (_true)); \
    _assert((metal::is_number_t<metal::integer<0>>), (_true)); \
    _assert((metal::is_number_t<metal::boolean<0>>), (_true)); \
/**/

_gen(_boilerplate)
