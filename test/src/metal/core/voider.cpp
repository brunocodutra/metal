// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/voider.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(M, N) \
    _assert((metal::is_just_t<metal::voider<_vals(N)>>), (_true)); \
    _assert((metal::voider_t<_vals(N)>), (void)); \
/**/

_gen(_boilerplate)
