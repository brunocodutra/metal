// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/map.hpp>
#include <metal/list/transpose.hpp>
#include <metal/pair/first.hpp>
#include <metal/pair/second.hpp>
#include <metal/lambda/arg.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::first>, metal::_1>, MAP(M)>), (metal::keys<MAP(M)>)); \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::second>, metal::_1>, MAP(M)>), (metal::values<MAP(M)>)); \
    ASSERT((metal::first<metal::transpose<MAP(INC(M))>>), (metal::keys<MAP(INC(M))>)); \
    ASSERT((metal::second<metal::transpose<MAP(INC(M))>>), (metal::values<MAP(INC(M))>)); \
    ASSERT((metal::at<MAP(LIMIT), metal::order<MAP(LIMIT), NUM(N)>>), (PAIR(N))); \
    ASSERT((metal::has_key<metal::erase_key<SEQ()<PAIRS(LIMIT)>, NUM(M)>, NUM(M)>), (FALSE)); \
/**/

GEN(MATRIX)
