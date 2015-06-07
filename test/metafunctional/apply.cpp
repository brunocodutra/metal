// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/apply.hpp>
#include <boost/mpl2/metafunctional/placeholders.hpp>

#include "test.hpp"

using namespace boost::mpl2;
using namespace boost::mpl2::placeholders;

BOOST_MPL2_ASSERT((std::is_same<apply_t<test::fundamental<>>, test::fundamental<>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::function<>>, test::function<>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::incomplete<>>, test::incomplete<>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::empty<>>, test::empty<>>));
BOOST_MPL2_ASSERT((std::is_same<apply_t<test::eponym<test::call>>, test::eponym<test::call>>));
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

int main()
{
    return 0;
}
