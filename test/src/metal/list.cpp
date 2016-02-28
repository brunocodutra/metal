// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/list.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/comparison/greater.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::flatten_t<metal::transform_t<metal::lambda<metal::list>, LIST(M)>>), (LIST(M))); \
    ASSERT((metal::flatten_t<metal::accumulate_t<LIST(M), metal::list<>, metal::lambda<metal::list>>>), (metal::list<VALS(M)>)); \
    ASSERT((metal::flatten_t<metal::list<metal::reduce_t<LIST(INC(M)), metal::lambda<metal::list>>>>), (metal::list<VALS(INC(M))>)); \
    ASSERT((metal::slice_t<LIST(M), metal::size_t<LIST(M)>, metal::size_t<LIST(M)>>), (LIST(M))); \
    ASSERT((metal::transform_t<metal::at<metal::quote_t<LIST(M)>, ARG(0)>, SEQ(M)<NUMS(M)>>), (LIST(M))); \
    ASSERT((metal::accumulate_t<VEC(M), metal::list<>, metal::push_front<metal::_2, metal::_1>, NUM(M), NUM(0)>), (metal::accumulate_t<VEC(M), metal::list<>, metal::push_back<metal::_1, metal::_2>>)); \
    ASSERT((metal::reduce_t<SEQ()<VECS(INC(M))>, metal::lambda<metal::join>, NUM(INC(M)), NUM(0)>), (metal::reduce_t<metal::reverse_t<SEQ()<VECS(INC(M))>>, metal::lambda<metal::join>>)); \
    ASSERT((metal::insert_t<VEC(M), NUM(M), VAL(N)>), (metal::push_back_t<VEC(M), VAL(N)>)); \
    ASSERT((metal::insert_t<VEC(M), NUM(0), VAL(N)>), (metal::push_front_t<VEC(M), VAL(N)>)); \
    ASSERT((metal::erase_t<VEC(INC(M)), NUM(M)>), (metal::pop_back_t<VEC(INC(M))>)); \
    ASSERT((metal::erase_t<VEC(INC(M)), NUM(0)>), (metal::pop_front_t<VEC(INC(M))>)); \
    ASSERT((metal::at_t<VEC(LIMIT), metal::find_t<VEC(LIMIT), VAL(M)>>), (VAL(M))); \
    ASSERT((metal::sort_t<SEQ(M)<NUMS(M)>, metal::greater<metal::_1, metal::_2>>), (metal::reverse_t<SEQ(M)<NUMS(M)>>)); \
    ASSERT((metal::same_t<metal::enumerate_t<NUM(M), NUM(N), NUM(0)>>), (TRUE)); \
/**/

GEN(MATRIX)
