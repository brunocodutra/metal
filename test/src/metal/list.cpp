// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/number/greater.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::flatten<metal::transform<metal::lambda<metal::list>, LIST(M)>>), (LIST(M))); \
    ASSERT((metal::flatten<metal::fold<LIST(M), metal::list<>, metal::lambda<metal::list>>>), (metal::list<VALS(M)>)); \
    ASSERT((metal::flatten<metal::list<metal::reduce<LIST(INC(M)), metal::lambda<metal::list>>>>), (metal::list<VALS(INC(M))>)); \
    ASSERT((metal::slice<LIST(M), NUM(0), metal::size<LIST(M)>>), (LIST(M))); \
    ASSERT((metal::transform<metal::bind<metal::lambda<metal::at>, metal::quote<LIST(M)>, metal::_1>, SEQ(M)<NUMS(M)>>), (LIST(M))); \
    ASSERT((metal::fold<VEC(M), metal::list<>, metal::lambda<metal::push_front>, NUM(M), NUM(0)>), (metal::fold<VEC(M), metal::list<>, metal::lambda<metal::push_back>>)); \
    ASSERT((metal::reduce<SEQ()<VECS(INC(M))>, metal::lambda<metal::join>, NUM(INC(M)), NUM(0)>), (metal::reduce<metal::reverse<SEQ()<VECS(INC(M))>>, metal::lambda<metal::join>>)); \
    ASSERT((metal::insert<VEC(M), NUM(M), VAL(N)>), (metal::push_back<VEC(M), VAL(N)>)); \
    ASSERT((metal::insert<VEC(M), NUM(0), VAL(N)>), (metal::push_front<VEC(M), VAL(N)>)); \
    ASSERT((metal::erase<VEC(INC(M)), NUM(M)>), (metal::pop_back<VEC(INC(M))>)); \
    ASSERT((metal::erase<VEC(INC(M)), NUM(0)>), (metal::pop_front<VEC(INC(M))>)); \
    ASSERT((metal::at<VEC(LIMIT), metal::find<VEC(LIMIT), VAL(M)>>), (VAL(M))); \
    ASSERT((metal::same<metal::enumerate<NUM(M), NUM(N), NUM(0)>>), (TRUE)); \
/**/

GEN(MATRIX)
