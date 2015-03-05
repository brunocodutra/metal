/*
 * This file is part of metalog, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE.txt for its full text.
 */

#define BOOST_MPL_LIMIT_METAFUNCTION_ARITY 5

#include <boost/mpl2/detail/preprocessor/typeof.hpp>
#include <boost/mpl2/detail/preprocessor/sizeof.hpp>
#include <boost/mpl2/seq.hpp>

typedef boost::mpl2::seq<>::type empty;
typedef boost::mpl2::seq<int, void, float>::type seq;

//template<typename>
//struct test;

//test<seq> a;

BOOST_MPL_TYPEOF(0+0) main()
{
    return seq::size + empty::size != 3;
}
