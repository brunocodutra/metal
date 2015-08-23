// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/nothing.hpp>

#include "test.hpp"

#define _boilerplate(_, N) \
    _assert((metal::is_nothing_t<_val(N)>), (_true)); \
    _assert((metal::is_nothing_t<_num(N)>), (_false)); \
/**/

_gen(_boilerplate)

_assert((metal::is_nothing_t<metal::nothing>), (_true));
