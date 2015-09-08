// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/lambda/arg.hpp>

#include "test.hpp"

ASSERT((metal::_1), (metal::arg<1U>));
ASSERT((metal::_2), (metal::arg<2U>));
ASSERT((metal::_3), (metal::arg<3U>));
ASSERT((metal::_4), (metal::arg<4U>));
ASSERT((metal::_5), (metal::arg<5U>));
ASSERT((metal::_6), (metal::arg<6U>));
ASSERT((metal::_7), (metal::arg<7U>));
ASSERT((metal::_8), (metal::arg<8U>));
ASSERT((metal::_9), (metal::arg<9U>));
