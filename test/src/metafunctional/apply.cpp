// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/apply.hpp>
#include <boost/mpl2/metafunctional/placeholders.hpp>

#include "test/variadic.hpp"
#include "test/types.hpp"
#include "test/expressions.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;
using namespace boost::mpl2::placeholders;

BOOST_MPL2_ASSERT((std::is_same<apply_t<test::a>, test::a>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::b>, test::b>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::c>, test::c>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::d>, test::d>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::e>, test::e>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::f>, test::f>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::g>, test::g>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::h>, test::h>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::i>, test::i>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::j>, test::j>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<test::call<>>, test::call<>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::evaluable<>>, test::evaluable<>::type>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<_1, void>, void>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<std::add_pointer<_1>, void>, void*>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<protect<lambda<std::add_pointer<_1>>>, void>, void*>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<test::wrapper, short, int, long, long long>, test::wrapper>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<protect<test::wrapper>, void>, test::wrap<void>>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<test::wrap<_1>, short, int, long, long long>, test::wrap<short>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::wrap<_1, _2>, short, int, long, long long>, test::wrap<short, int>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::wrap<_1, _2, _3>, short, int, long, long long>, test::wrap<short, int, long>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::wrap<_1, _2, _3, _4>, short, int, long, long long>, test::wrap<short, int, long, long long>>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<lambda<_1>, void>, lambda<void>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<protect<lambda<_1>>, void>, void>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<lambda<_1>, protect<_1>>, lambda<protect<_1>>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<protect<_1>, lambda<_1>>, lambda<_1>>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<quoter<protect>, _1>, quoter<protect>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<protect<quoter<protect>>, _1>, protect<_1>>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<apply<std::add_pointer<_1>, void>, void*>, void**>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<call<_1, void>, lambda<std::add_pointer<_1>>>, void*>));

BOOST_MPL2_ASSERT((std::is_same<apply_t<apply<std::add_pointer<_1>, void>, void*>, void**>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<apply<_1, void>, std::add_pointer<_1>>, void*>));

using compose = apply<_1, apply<_2, _3>>;
BOOST_MPL2_ASSERT((std::is_same<apply_t<compose, std::add_pointer<_1>, std::add_const<_1>, void>, void const*>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<compose, std::add_const<_1>, std::add_pointer<_1>, void>, void* const>));

using once = apply<protect<lambda<compose>>, protect<_1>, _1, _2>;
BOOST_MPL2_ASSERT((std::is_same<apply_t<once, std::add_pointer<_1>, void>, void*>));

using twice = apply<protect<lambda<compose>>, _1, _1, _2>;
BOOST_MPL2_ASSERT((std::is_same<apply_t<twice, std::add_pointer<_1>, void>, void**>));

using thrice = apply<protect<lambda<once>>, _1, apply<protect<lambda<twice>>, _1, _2>>;
BOOST_MPL2_ASSERT((std::is_same<apply_t<thrice, std::add_pointer<_1>, void>, void***>));

using ptr2ptr2ptr = apply<protect<lambda<thrice>>, protect<lambda<std::add_pointer<_1>>>, _1>;
BOOST_MPL2_ASSERT((std::is_same<apply_t<ptr2ptr2ptr, void>, void***>));
